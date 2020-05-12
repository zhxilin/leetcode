//1145. Binary Tree Coloring Game
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        //思路：选定的节点x将整颗树切割为3部分：左子树l、右子树r、根及其他节点n - 1 - l - r
        //获胜的条件即判定这3部分任意一部分的数量超过半数以上节点n/2即可，
        //意味着后手只要在上述3部分中找到一部分数量大于n/2的着色即可获胜
        int leftCnt = 0, rightCnt = 0;
        dfs(root, x, leftCnt, rightCnt);
        
        int target = n / 2;
        return leftCnt > target || rightCnt > target || n - 1 - leftCnt - rightCnt > target;
    }
    
    
    //求x子树总节点数量
    int dfs(TreeNode* root, int x, int& leftCnt, int& rightCnt) {
        if (!root) return 0;
        
        //子树节点总数 = 左子树节点总数 + 右子树节点总数 + 1（根）
        int left = dfs(root->left, x, leftCnt, rightCnt);
        int right = dfs(root->right, x, leftCnt, rightCnt);
        
        //保存切割点的左右子树节点数量
        if (root->val == x) {
            leftCnt = left;
            rightCnt = right;
        }
        
        return left + right + 1;
    }
};