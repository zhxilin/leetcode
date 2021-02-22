//1641. Count Sorted Vowel Strings
class Solution {
public:
    int countVowelStrings(int n) {
        //dp[i]表示按字典序用i个元音能组成的字符串数量
        vector<int> dp(5, 1);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < 5; ++j) {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        
        return dp[4];
    }
};