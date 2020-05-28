//337. House Robber III
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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> mx;
        return dfs(root, mx);
    }
    
    int dfs(TreeNode* root, unordered_map<TreeNode*, int>& mx) {
        if (!root) return 0;
        
        if (!root->left && !root->right) return root->val;
        
        if (mx.count(root)) return mx[root];
         
        //偷法1：root和孙子节点
        int result1(root->val);
        if (root->left)
            result1 += dfs(root->left->left, mx) + dfs(root->left->right, mx);
        if (root->right)
            result1 += dfs(root->right->left, mx) + dfs(root->right->right, mx);
        
        //偷法2：仅子节点
        int result2 = dfs(root->left, mx) + dfs(root->right, mx);
        
        //两种偷法取最大，即为该节点的最大偷法
        int maxValue = max(result1, result2);
        mx[root] = maxValue;
        
        return maxValue;
    }
};