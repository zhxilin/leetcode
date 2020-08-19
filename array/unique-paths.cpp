//62. Unique Paths
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        
        //首列和首行每个格子必定只有唯一路径
        for (int i = 0; i < m; ++i)
            dp[i][0] = 1;
        
        for (int j = 0; j < n; ++j)
            dp[0][j] = 1;
        
        //其余格子的路径为左格子和上格子的子问题路径之和
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();