//1302. Deepest Leaves Sum
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int nDepth = getDepth(root);
        
        int sum = 0;
        dfs(root, nDepth, 1, sum);
        
        return sum;
    }
    
    void dfs(TreeNode* root, int nDepth, int nCurDepth, int& sum) {
        if (!root) return;
        
        if (nCurDepth == nDepth) {
            sum += root->val;
            return;
        }
        
        dfs(root->left, nDepth, nCurDepth + 1, sum);
        dfs(root->right, nDepth, nCurDepth + 1, sum);
    }
    
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return max(left, right) + 1;
    }
};