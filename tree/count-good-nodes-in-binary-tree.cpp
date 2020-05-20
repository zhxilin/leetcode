//1448. Count Good Nodes in Binary Tree
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
    int goodNodes(TreeNode* root) {
        int result = 0;
        dfs(root, result, INT_MIN);
        return result;
    }
    
    void dfs(TreeNode* root, int& result, int pathMax) {
        if (!root) return;                
                
        if (root->val >= pathMax) {
            result++;
            pathMax = root->val;
        }
                
        dfs(root->left, result, pathMax);
        dfs(root->right, result, pathMax);
    }
};