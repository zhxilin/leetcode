//124. Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        
        dfs(root, maxSum);
        
        return maxSum;
    }
    
    int dfs(TreeNode* root, int& maxSum) {
        if (!root) return 0;
        
        //后序遍历，先计算左右子树的最大和
        int l = dfs(root->left, maxSum);
        int r = dfs(root->right, maxSum);
        
        int maxLeft = max(l, 0);
        int maxRight = max(r, 0);
        
        //最大值由根、左、右子树最大和三者之和组成
        maxSum = max(maxSum, root->val + maxLeft + maxRight);
        
        //返回当前节点的最大和，即当前节点与左右子树较大和之和
        return root->val + max(maxLeft, maxRight);
    }
};