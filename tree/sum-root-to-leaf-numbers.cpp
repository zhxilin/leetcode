//129. Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        int sum = 0, val = 0;
        
        treePath(root, sum, val);
        
        return sum;
    }
    
    void treePath(TreeNode* root, int& sum, int val) {
        if (!root) return;
        
        val = val * 10 + root->val;
        
        if (!root->left && !root->right) {
            sum += val;
            return;
        }        
        
        //注意val为传值参数，每一层往深度走时需要复制该值
        if (root->left)
            treePath(root->left, sum, val);
        
        if (root->right)
            treePath(root->right, sum, val);
    }
};