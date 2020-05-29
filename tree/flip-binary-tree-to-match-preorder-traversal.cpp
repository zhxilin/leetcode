//971. Flip Binary Tree To Match Preorder Traversal
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> result;
        int index = 0;
        if (dfs(root, voyage, index, result))
            return result;
        
        return {-1};
    }
    
    bool dfs(TreeNode* root, vector<int>& voyage, int& index, vector<int>& result) {
        if (!root) return true;
        
        if (root->val != voyage[index++]) return false;
        
        if(root->left && root->left->val != voyage[index]) {
            swap(root->left, root->right); 
            result.push_back(root->val);
        }
        
        return dfs(root->left, voyage, index, result) && 
            dfs(root->right, voyage, index, result);
    }
};