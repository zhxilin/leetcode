//865. Smallest Subtree with all the Deepest Nodes
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* result;
        int maxDepth = INT_MIN;
        dfs(root, maxDepth, 0, result);
        return result;
    }
    
    int dfs(TreeNode* root, int& maxDepth, int depth, TreeNode* &result) {
        if (!root) return 0;
        
        //DFS计算以左右子树为根节点时的最大深度
        int leftMaxDepth = dfs(root->left, maxDepth, depth + 1, result);
        int rightMaxDepth = dfs(root->right, maxDepth, depth + 1, result);
        
        //当前节点的最大深度
        int curMaxDepth = max({depth, leftMaxDepth, rightMaxDepth});
        
        //如果左右子树的最大深度都相同(包含没有左右子节点的情况)，那就需要更新结果为当前节点
        if (leftMaxDepth == rightMaxDepth && curMaxDepth >= maxDepth) {
            maxDepth = curMaxDepth;
            result = root;
        }
        
        return curMaxDepth;
    }
};