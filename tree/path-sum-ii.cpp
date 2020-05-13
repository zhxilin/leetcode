//113. Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vec, result;
        vector<int> vPath;
        treePath(root, vec, vPath);
        
        for (auto& path : vec) {
            int accumulate = 0;
            for (int i = 0; i < path.size(); ++i) {
                accumulate += path[i];
            }
            if (sum == accumulate)
                result.push_back(std::move(path));
        }
        
        return result;
    }
    
    void treePath(TreeNode* root, vector<vector<int>>& vec, vector<int> vPath) {
        if (!root) return;
        
        vPath.push_back(root->val);
        
        if (!root->left && !root->right) {
            vec.push_back(vPath);
            return;
        }        
        
        if (root->left)
            treePath(root->left, vec, vPath);
        
        if (root->right)
            treePath(root->right, vec, vPath);
    }
};