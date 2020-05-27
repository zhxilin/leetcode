//236. Lowest Common Ancestor of a Binary Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {   
        TreeNode* result;
        dfs(root, p, q, result);        
        return result;
    }
    
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &result) {
        if (!root) return false;
        
        bool leftFoundOne = dfs(root->left, p, q, result);
        bool rightFoundOne = dfs(root->right, p, q, result);
        
        //当前节点是否与其中一个目标节点相同
        bool foundOne = root == p || root == q;
        
        //当前节点、左子树、右子树中任意2个包含目标节点，则代表找到结果
        if (foundOne && leftFoundOne || foundOne && rightFoundOne || leftFoundOne && rightFoundOne)
            result = root;
        
        //返回当前节点的子树是否包含目标节点
        return foundOne || leftFoundOne || rightFoundOne;
    }
    
};