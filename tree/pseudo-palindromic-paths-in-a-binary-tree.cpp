//1457. Pseudo-Palindromic Paths in a Binary Tree
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
    int pseudoPalindromicPaths (TreeNode* root) {
        //思路：排序能组成回文的条件是每条路径上的数值最多只能有一个出现奇数次
        vector<int> digitCnt(9); //数字1-9的出现次数
        return dfs(root, digitCnt);
    }
    
    int dfs(TreeNode* root, vector<int> digitCnt) {
        if (!root) return 0;
        
        //记录每个数字出现过的次数
        digitCnt[root->val - 1]++;
        //dfs到叶子节点则开始判断是否回文
        if(!root->left && !root->right) 
            return isPalindrom(digitCnt);
        
        int left = dfs(root->left, digitCnt);        
        int right = dfs(root->right, digitCnt);
        
        return left + right;
    }
    
    bool isPalindrom(vector<int>& digitCnt) {
        int oddCnt = 0;
        for (int cnt : digitCnt) {
            if (cnt % 2 == 1)
                oddCnt++;
        }
        return oddCnt <= 1;
    }
};