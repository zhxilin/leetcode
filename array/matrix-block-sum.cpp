//1314. Matrix Block Sum
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1)), result(m, vector<int>(n));
        
        for (int i = 1 ; i < m+1 ; ++i) {
            for (int j = 1 ; j < n+1; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + mat[i - 1][j - 1] - dp[i - 1][j - 1];
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                int r1 = max(i - K, 0);
                int r2 = min(i + K, m - 1);
                int c1 = max(j - K, 0);
                int c2 = min(j + K, n - 1);
                
                result[i][j] = dp[r2 + 1][c2 + 1] - dp[r2 + 1][c1] - dp[r1][c2 + 1] + dp[r1][c1];
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