//968. Binary Tree Cameras
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
    int minCameraCover(TreeNode* root) {
        //思路：
        //每个节点可以分为3种状态：0=需要放置，1=已被覆盖，2=已放置
        
        int count = 0;
        //贪心算法
        if (0 == dfs(root, count))
            count++;
        
        return count;
    }
    
    int dfs(TreeNode* root, int& count) {
        if (!root) 
            return 1;
        
        if (!root->left && !root->right) 
            return 0;
        
        int leftState = dfs(root->left, count);
        int rightState = dfs(root->right, count);
        
        //若左右子节点有一个需要放置，即未覆盖，则当前根节点肯定需要放置
        if (0 == leftState || 0 == rightState) {
            count++;
            return 2;
        }
        
        //若左右子节点有一个已放置，则当前根节点已被覆盖
        if (2 == leftState || 2 == rightState)
            return 1;
        
        //其余状况军表示需要放置
        return 0;
    }
};