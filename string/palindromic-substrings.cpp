//647. Palindromic Substrings
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        //dp[i][j]表示子串s[i..j]是否为回文串
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        int result = 0;
        //base case 1: 单字符回文串
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            result++;
        }
        
        //base case 2: 双字符回文串
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                result++;
            }
        }
        
        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                int j = i + k - 1;
                
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    result++;
                }
            }
        }
        
        return result;
    }
};