//662. Maximum Width of Binary Tree
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        //思路：树结构按BFS展开成数组后，可以得到一组下标关系，位置为n的节点，其左节点位置为2n，右节点为2n + 1
        //找到每一层的最左节点和最右节点的两个位置lm, rm，其间的宽度即为rm - lm + 1
        queue<pair<TreeNode*,int>> q;//<节点,节点的位置>
        q.push({root, 0});
        
        int result = 0;
        while (!q.empty()) {
            int lm = INT_MAX, rm = 0; //最左节点位置，最右节点位置
            int offset = q.front().second;
            int size = q.size();
            
            while (size--) {
                TreeNode* node = q.front().first;
                int pos = q.front().second;
                q.pop();
                
                if (pos < lm) lm = pos;
                if (pos > rm) rm = pos;
                
                if (node->left) 
                    q.push({node->left, 2 * (pos - offset)});
                
                if (node->right)
                    q.push({node->right, 2 * (pos - offset) + 1});
            }            
            
            result = max(result, rm - lm + 1);
        }
        
        return result;
    }
};