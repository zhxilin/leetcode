//1277. Count Square Submatrices with All Ones
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n));
        
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n;++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else 
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    
                    result += dp[i][j];
                }
            }
        }
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();