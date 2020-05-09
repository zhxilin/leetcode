//105. Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            mx[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
     /* 思路
        前序：根->左->右，中序：左->根->右
        前序根的下一个位置必为左子树的根，现在根、左子树根找到了，目标就是找到右子树的根在哪里，换言之，找到左子树的长度
        为了找到左子树的长度，则需要借助中序
        在中序找到前序根的位置，即可确定中序的分割点，即可换算出左子树的长度
        确定了左子树的长度，就可以分别把前序和后序切割成3部分了，进入递归过程即可
    */
    TreeNode* build(vector<int>& pre, int preBegin, int preEnd, vector<int>& in, int inBegin, int inEnd) {
        
        if (preBegin == preEnd) return NULL;
        
        TreeNode* root = new TreeNode(pre[preBegin]);
        
        if (preEnd - preBegin == 1) return root;
        
        int subLeftLength = 0;
        //加速查找O(1)
        if (mx.count(pre[preBegin]))
            subLeftLength = mx[pre[preBegin]] - inBegin;
        
        root->left = build(pre, preBegin + 1, preBegin + 1 + subLeftLength, in, inBegin, inBegin + subLeftLength);
        root->right = build(pre, preBegin + 1 + subLeftLength, preEnd, in, inBegin + subLeftLength + 1, inEnd - 1);
        
        return root;
    }
       
private:
    unordered_map<int, int> mx;
};