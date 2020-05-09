//106. Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         for (int i = 0; i < inorder.size(); ++i) {
            mx[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    
     /* 思路
        中序：左->根->右，后序：左->右->根
        在中序中找到根的位置，即可确定分割点，即确定了左右子树的范围
        要确定中序根的位置，需要借助后序，后序的末位置即为根，如此一来即可确定左子树的长度
        确定了左子树的长度，就可以分别把前序和后序切割成3部分了，进入递归过程即可
    */
    TreeNode* build(vector<int>& in, int inBegin, int inEnd, vector<int>& post, int postBegin, int postEnd) {
        
        if (postBegin == postEnd) return NULL;
        
        TreeNode* root = new TreeNode(post[postEnd - 1]);
        
        if (postEnd - postBegin == 1) return root;
        
        int subLeftLength = 0;
        //加速查找O(1)
        if (mx.count(post[postEnd - 1]))
            subLeftLength = mx[post[postEnd - 1]] - inBegin;
        
        root->left = build(in, inBegin, inBegin + subLeftLength, post, postBegin, postBegin + subLeftLength);
        root->right = build(in, inBegin + subLeftLength + 1, inEnd, post, postBegin + subLeftLength, postEnd - 1);
        
        return root;
    }
       
private:
    unordered_map<int, int> mx;
};