//655. Print Binary Tree
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
    vector<vector<string>> printTree(TreeNode* root) {
        //获取树高
        int height = getHeight(root);
        //树宽 = 2^树高 - 1
        int width = (1 << height) - 1;
        
        //将二维数组全部初始化为空串
        vector<vector<string>> result(height, vector<string>(width, ""));
        
        //dfs将树节点的值填补到二维数组对应的位置
        dfs(root, result, 0, 0, width - 1);
        
        return result;
    }
    
private:
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    
    void dfs(TreeNode* root, vector<vector<string>>& result, int height, int left, int right) {
        if (!root) return;
        
        //中点放置根
        int mid = (left + right) / 2;
        result[height][mid] = to_string(root->val);
        
        //中点切割为左右两部分，即为左右子树
        dfs(root->left, result, height + 1, left, mid - 1);
        dfs(root->right, result, height + 1, mid + 1, right);
    }
};