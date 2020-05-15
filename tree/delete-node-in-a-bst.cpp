//450. Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else {         
            //找到目标节点
            if (!root->left)
                return root->right;
            
            if (!root->right)
                return root->left;
            
            //左右子节点均非空
            
            //将右子树的最左叶子节点提上来作为删除后的根
            TreeNode* leftMost = root->right;
            while (leftMost->left) 
                leftMost = leftMost->left;
            
            root->val = leftMost->val;
            root->right = deleteNode(root->right, leftMost->val);
        }
        return root;
    }
};