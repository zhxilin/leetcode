//96. Unique Binary Search Trees
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                //以j为根（分割点）划分为左子树和右子树
                //左子树包含1,2,3,..,j - 1.
                int left = j - 1;
                //右子树包含j + 1, j + 2, ..., i
                int right = i - j;
                //以j为根的不同构BST数目 = dp[left] * dp[right]
                dp[i] += dp[left] * dp[right];
            }
        }
        
        return dp[n];
    }
};