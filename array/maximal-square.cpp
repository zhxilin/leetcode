//221. Maximal Square
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m <= 0) return 0;
        
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n, 0));
        int maxSide = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {               
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0)
                        dp[i][j] = matrix[i][j] - '0';
                    else 
                        dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
                
        return maxSide * maxSide;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();