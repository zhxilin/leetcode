//988. Smallest String Starting From Leaf
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
    string smallestFromLeaf(TreeNode* root) {
        vector<string> vec;
        string str;
        treePath(root, vec, str);
        
        if (vec.empty()) return "";
        
        string result;
        for (const string& str: vec) {            
            if (result.empty())
                result = str;
            else if (str < result)
                result = str;
        }
        
        return result;
    }
    
    void treePath(TreeNode* root, vector<string>& vec, string str) {
        if (!root) return;
        
        str += char(97 + root->val);
        
        if (!root->left && !root->right) {
            vec.push_back(string(str.rbegin(), str.rend()));
            return;
        }        
        
        if (root->left)
            treePath(root->left, vec, str);
        
        if (root->right)
            treePath(root->right, vec, str);
    }
};