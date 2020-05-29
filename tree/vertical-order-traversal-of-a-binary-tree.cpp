//987. Vertical Order Traversal of a Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct Node {
        Node(int v, int y) : val(v), y(y) {}
        int y;
        int val;
        bool operator<(const Node& rhs) const {
            if (y == rhs.y) 
                return val < rhs.val;
            return y > rhs.y;
        }
    };
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //用map而不用unordered_map是因为map会根据key自动排序
        //所以以x为key可以天然由小到大排序
        map<int, vector<Node>> mx;
        //用dfs求每个节点的x,y信息
        dfs(root, 0, 0, mx);
        
        vector<vector<int>> result;
        for (auto itr = mx.begin(); itr != mx.end(); ++itr) {
            //每组x中的元素，按y和值排序
            sort(itr->second.begin(), itr->second.end());
            
            vector<int> inner;
            for (const Node& node : itr->second) {
                inner.push_back(node.val);
            }
            result.push_back(move(inner));
        }
        
        return result;
    }
    
    void dfs(TreeNode* root, int x, int y, map<int, vector<Node>>& mx) {
        if (!root) return;
        
        mx[x].emplace_back(root->val, y);
        
        dfs(root->left, x - 1, y - 1, mx);
        dfs(root->right, x + 1, y - 1, mx);
    }
};