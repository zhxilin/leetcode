//120. Triangle
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        dp[0][0] = triangle[0][0];
        
        //dp:每个位置的路径和为当前值+上一层相邻两个位置的最小路径和
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = triangle[i][j] + min(dp[i - 1][max(0, j - 1)], dp[i - 1][min(j, i - 1)]);
            }
        }
        
        int result = INT_MAX;
        for (int val : dp[n - 1])
            result = min(result, val);
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();