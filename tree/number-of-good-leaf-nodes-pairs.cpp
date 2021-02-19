//1530. Number of Good Leaf Nodes Pairs
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
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);        
        return result;
    }

private:
    int result = 0;
    
    vector<int> dfs(TreeNode* root, int distance) {
        vector<int> dists;
        
        if (!root) return dists;
        
        auto left = dfs(root->left, distance);
        auto right = dfs(root->right, distance);
        
        if (left.empty() && right.empty()) {
            dists.push_back(1);
            return dists;
        }
        
        for (int i = 0; i < left.size(); ++i) {
            for (int j = 0; j < right.size(); ++j) {
                if (left[i] + right[j] <= distance)
                    result++;
            }
        }
        
        for (int i = 0; i < left.size(); ++i) {
            left[i]++;
            dists.push_back(left[i]);
        }
        
        for (int i = 0; i < right.size(); ++i) {
            right[i]++;
            dists.push_back(right[i]);
        }
        
        return dists;
    }
};