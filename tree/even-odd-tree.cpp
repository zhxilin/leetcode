//1609. Even Odd Tree
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
    bool isEvenOddTree(TreeNode* root) {
        q.push(root);
        
        int level = 0;
        while (!q.empty()) {
            
            int size = q.size();
            
            bool even = level % 2 == 0;
            
            int lastVal = even ? INT_MIN : INT_MAX;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                
                if (even) {
                    //check strictly increasing
                    if (node->val % 2 == 0 || node->val <= lastVal)
                        return false;
                } else {
                    //check strictly decreasing
                    if (node->val % 2 != 0 || node->val >= lastVal)
                        return false;
                }
                lastVal = node->val;
                
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
            level++;
        }
        
        return true;
    }
    
    queue<TreeNode*> q;
};