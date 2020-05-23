//652. Find Duplicate Subtrees
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> mx;
        
        dfs(root, mx, result);
        
        return result;
    }
    
    string dfs(TreeNode* root, unordered_map<string, int>& mx, vector<TreeNode*>& result) {
        if (!root) return "#";
        
        //序列化树结构
        stringstream ss;
        ss << "{" << root->val << "}, {"<< dfs(root->left, mx, result) << "}, {" << dfs(root->right, mx, result) << "}";
        
        string tree = ss.str();   
        
        //dfs过程如果发现已有相同的序列化结构，且出现次数为1（重复的不计），则该节点为根的子树为所求的重复子树
        if (mx.count(tree) && mx[tree] == 1)
            result.push_back(root);
           
        mx[tree]++;
        
        return tree;
    }
};