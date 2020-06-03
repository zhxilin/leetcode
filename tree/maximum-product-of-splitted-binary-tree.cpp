//1339. Maximum Product of Splitted Binary Tree
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
    int maxProduct(TreeNode* root) {
        
        const int mod = 1e9 + 7;
        
        vector<long long> sums;
        dfs(root, sums);
        
        long long total = dfs(root, sums);
        long long maxProduct = LLONG_MIN;
        for (long long i : sums) {
            long long product = i * (total - i);
            maxProduct = max(maxProduct, product);
        }
        return maxProduct % mod;
    }
    
    long long dfs(TreeNode* root, vector<long long>& sums) {
        if (!root) return 0;
        
        long long sum = root->val + dfs(root->left, sums) + dfs(root->right, sums);
        sums.push_back(sum);
        
        return sum;
    }
};