//623. Add One Row to Tree
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root)
            return new TreeNode(v);
        
        if (1 == d) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
                
        //思路：通过BFS找出深度为d的节点的父节点（即d-1的所有节点插入新节点)
        queue<TreeNode*> q;
        q.push(root);
                
        int depth = 1;
        while (!q.empty()) {
            //每次循环取到的size即为当层的个数
            int size = q.size();
            
            //按层出队，同时每个节点的子节点入队
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                
                if (depth == d - 1) {
                    TreeNode* left = node->left;  
                    TreeNode* right = node->right;
                    node->left = new TreeNode(v);
                    node->right = new TreeNode(v);
                    node->left->left = left;
                    node->right->right = right;
                }
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            depth++;
        }
        
        return root;
    }    
};