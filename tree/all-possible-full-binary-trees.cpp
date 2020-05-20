//894. All Possible Full Binary Trees
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        //偶数点必不可能构成完全二叉树
        if (N % 2 == 0) return {};
        
        //DFS + DP
        if (mx.count(N))
            return mx[N];
                
        //DP拆解子问题：如{7}应解子问题{1}+{5}，{3}+{3}，{5}+{1}
        vector<TreeNode*> subProblem;
        if (1 == N) 
            subProblem.push_back(new TreeNode(0));
        else {
            for (int i = 1; i <= N - 2; i += 2) {
                //子问题左子树为i时，右子树则对应为N-1-i
                vector<TreeNode*> leftTree = allPossibleFBT(i);
                vector<TreeNode*> rightTree = allPossibleFBT(N - 1- i);
                
                for (TreeNode* l : leftTree) {
                    for (TreeNode* r : rightTree) {
                        TreeNode* root = new TreeNode(0);
                        root->left = l;
                        root->right = r;
                        subProblem.push_back(root);
                    }
                }
            }
        }
        
        mx[N] = subProblem;
        
        return subProblem;
    }

private:
    unordered_map<int, vector<TreeNode*>> mx;
};