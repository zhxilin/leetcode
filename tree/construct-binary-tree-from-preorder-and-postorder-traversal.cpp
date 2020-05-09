//889. Construct Binary Tree from Preorder and Postorder Traversal
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        for (int i = 0; i < post.size(); ++i) {
            mx[post[i]] = i;
        }
        return buildTree(pre, 0, pre.size(), post, 0, post.size());
    }
    
    /* 思路
        前序：根->左->右，后序：左->右->根
        前序根的下一个位置必为左子树的根，现在根、左子树根找到了，目标就是找到右子树的根在哪里，换言之，找到左子树的长度
        为了找到左子树的长度，则需要借助后序
        前序左子树的首元素等于后序左子树的末元素，利用这个特性，可以用后序确定左子树的长度。
        确定了左子树的长度，就可以分别把前序和后序切割成3部分了，进入递归过程即可
    */
    
    TreeNode* buildTree(vector<int>& pre, int preBegin, int preEnd, vector<int>& post, int postBegin, int postEnd) {
        
        if (preBegin == preEnd) return NULL;
        
        TreeNode* root = new TreeNode(pre[preBegin]);
        
        if (preEnd - preBegin == 1) return root;
        
        int subLeftLength = 0;
        //加速查找O(1)
        if (mx.count(pre[preBegin + 1]))
            subLeftLength = mx[pre[preBegin + 1]] - postBegin + 1;
        
        root->left = buildTree(pre, preBegin + 1, preBegin + 1 + subLeftLength, post, postBegin, postBegin + subLeftLength);
        root->right = buildTree(pre, preBegin + 1 + subLeftLength, preEnd, post, postBegin + subLeftLength, postEnd - 1);
        
        return root;
    }
    
private:
    unordered_map<int, int> mx;
};