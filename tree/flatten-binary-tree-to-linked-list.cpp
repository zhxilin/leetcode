//114. Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if (!root) return;
 
        TreeNode* left = root->left;
        TreeNode* right = root->right;
 
        //清空根的左子树
        root->left = NULL;
 
        //dfs处理左右子树
        flatten(left);
        flatten(right);
 
        //处理完的左子树直接挂在root的右节点
        root->right = left;
        
        //取出最右叶子节点
        TreeNode* node = root;
        while (node->right) 
            node = node->right;
        
        //最右叶子节点的右节点挂上处理完的右子树即可
        node->right = right;  
    }
};