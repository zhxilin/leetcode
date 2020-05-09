//102. Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        //BFS
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> result;
        
        while (!q.empty()) {
            //每次循环取到的size即为当层的个数
            int size = q.size();
            vector<int> level;
            
            //按层出队，同时每个节点的子节点入队
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                
                level.push_back(node->val);
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            
            result.push_back(level);
        }
        
        return result;
    }
};