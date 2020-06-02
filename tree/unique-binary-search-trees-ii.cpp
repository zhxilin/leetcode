//95. Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) return {};
        
        return dfs(1, n);
    }
    
    vector<TreeNode*> dfs(int start, int end) {
        if (start > end) return {NULL};

        vector<TreeNode*> result;
        //以i为根节点（其左子树和右子树也都是BST）的组合数量即为
        //左子树数量*右子树数量
        for (int i = start; i <= end; ++i) {            
            vector<TreeNode*> lefts = dfs(start, i - 1);
            vector<TreeNode*> rights = dfs(i + 1, end);
            
            for (auto&& left : lefts) {
                for (auto&& right : rights) {
                    result.push_back(new TreeNode(i, left, right));
                }
            }
        }
        return result;
    }
};