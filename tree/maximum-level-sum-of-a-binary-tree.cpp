//1161. Maximum Level Sum of a Binary Tree
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
    queue<TreeNode*> q;
    int maxLevelSum(TreeNode* root) {
        if (!root) 
            return 0;
        
        int result = 0;
        int level = 0, maxsum = INT_MIN;
        
        q.push(root);
        while (!q.empty()) {
            int sum = 0, n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                sum += node->val;
                
                q.pop();
                
                if (node->left)
                    q.push(node->left);
                
                if (node->right)
                    q.push(node->right);
            }
            level++;
            
            if (sum > maxsum) {
                maxsum = sum;
                result = level;
            }
        }
        return result;
    }
};