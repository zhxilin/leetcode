//99. Recover Binary Search Tree`
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
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL, *second = NULL, *last = NULL;
        inorder(root, &first, &second, &last);
        if (first && second)
            swap(first->val, second->val);
    }
    
    void inorder(TreeNode* root, TreeNode** first, TreeNode** second, TreeNode** last) {
        
        if (!root) return;
        
        inorder(root->left, first, second, last);
        
        if (*last && (*last)->val > root->val) {
            if (!*first)
                *first = *last;
            *second = root;
        }
        
        *last = root;
        
        inorder(root->right, first, second, last);
    }
};