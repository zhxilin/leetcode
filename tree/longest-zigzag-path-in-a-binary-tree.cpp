//1372. Longest ZigZag Path in a Binary Tree
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
    int longestZigZag(TreeNode* root) {
        //根节点的左方向
        dfs(root, 0, 0);
        //根节点的右开始
        dfs(root, 1, 0);
        return result;
    }
    
    int result = INT_MIN;
    
    void dfs(TreeNode* root, int direction, int path) {
        if (!root) return;
                
        result = max(result, path);
        
        if (0 == direction) {
            //当前方向是左，则下一次dfs的方向改为右
            //同时右子节点的长度可以累加1，而左子节点长度从0开始
            dfs(root->right, 1, path + 1);
            dfs(root->left, 1, 0);
        } else {
            //当前方向是右，则下一次dfs的方向改为左
            //同时左子节点的长度可以累加1，而右子节点长度从0开始
            dfs(root->left, 0, path + 1);
            dfs(root->right, 0, 0);
        }
    }
};