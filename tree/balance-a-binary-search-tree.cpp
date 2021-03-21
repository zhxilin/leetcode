//1382. Balance a Binary Search Tree
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        
        return createBST(vals, 0, vals.size() - 1);
    }
    
private:
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
    
    TreeNode* createBST(const vector<int>& vals, const int start, const int end) {
        if (start > end)
            return nullptr;
        
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(vals[mid]);
        root->left = createBST(vals, start, mid - 1);
        root->right = createBST(vals, mid + 1, end);
        return root;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
