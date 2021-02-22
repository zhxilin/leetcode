//5. Longest Palindromic Substring
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        //dp[i][j]表示子串s[i..j]是否为回文子串
        vector<vector<int>> dp(n, vector<int>(n));
        
        int maxlen = 0, start = 0;
        
        //base case 1: 长度为1的回文子串
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            maxlen = 1;
            start = 0;
        }
        
        //base case 2: 长度为2的回文子串
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                maxlen = 2;
                start = i;
            }
        }
        
        //k为子串长度
        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                //i为子串头,j为子串尾
                int j = i + k - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    if (maxlen < k) {
                        maxlen = k;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, maxlen);
    }
};