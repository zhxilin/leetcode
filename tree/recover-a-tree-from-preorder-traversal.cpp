//1028. Recover a Tree From Preorder Traversal
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
    TreeNode* recoverFromPreorder(string S) {
        unordered_map<int, TreeNode*> mx;
        
        int depth = 0;
        
        for (int i = 0; i < S.size(); ) {
            if (S[i] == '-') {
                depth++;
                ++i;
                continue;
            }
            
            //取出数值
            stringstream ss;
            while (i < S.size() && S[i] >= '0' && S[i] <= '9') {
                ss << S[i++];
            }
            
            int val = stoi(ss.str());
            
            //由于是前序遍历，左子树总先于右子树处理，相同深度的左节点此前已处理过（不管是否已填满左右节点），
            //此处新建的节点认为是右节点，直接覆盖，往下处理的子节点会挂到这个节点下
            mx[depth] = new TreeNode(val);
            
            //将新节点挂到上层节点的非空左子节点或右子节点
            if (depth > 0) {
                if (mx[depth - 1]->left)
                    mx[depth - 1]->right = mx[depth];
                else
                    mx[depth - 1]->left = mx[depth];
            }
            
            //重置深度
            depth = 0;
        }
        
        return mx[0];
    }
};