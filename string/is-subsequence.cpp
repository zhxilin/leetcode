//392. Is Subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return false;
        
        //对于s[0,..i-1]和t[0,..j-1],他们的最长公共长度是dp[i][j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[m][n] >= m;
    }
};