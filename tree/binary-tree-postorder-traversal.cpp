//145. Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> vec;
        if (!root) return vec;
        
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* lastVisit;
        
        //后序遍历：左、右、中
        
        //先把cur移动到根的最左子节点，途径的节点入栈
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        
        while (!s.empty()) {
            cur = s.top();
            
            //注意：一个节点可被访问的条件是：无右子节点或右子节点已被访问过
            if (!cur->right || cur->right == lastVisit) {
                vec.push_back(cur->val);
                lastVisit = cur;
                s.pop();
            } else {
                //右子节点未被访问过，则要将cur移动到右子树的最左子节点，继续迭代
                cur = cur->right;
                while (cur) {
                    s.push(cur);
                    cur = cur->left;
                }
            }
        }
        
        return vec;
    }
};