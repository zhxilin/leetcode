//931. Minimum Falling Path Sum
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        for (int i = 0; i < n; ++i) {
            dp[0][i] = A[0][i];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int minCol = max(j - 1, 0), maxCol = min(j + 1, n - 1);
                dp[i][j] = A[i][j] + min({dp[i - 1][minCol], dp[i - 1][j], dp[i - 1][maxCol]});
            }
        }
        
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();