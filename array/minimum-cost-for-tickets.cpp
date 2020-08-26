//983. Minimum Cost For Tickets
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.back();
        
        vector<int> dp(n + 1); //截止第i天的花费
        
        for (int i = 1, j = 0; i <= n; ++i) {
            //若日期上有这一天，那么这一天的花费为以下dp公式；如果不在日期上，则它是被覆盖的天数，沿用上一天的花费
            if (i == days[j]) {
                j++;
                dp[i] = min({
                    costs[0] + dp[i - 1],
                    costs[1] + dp[i - min(i, 7)],
                    costs[2] + dp[i - min(i, 30)],
                });
            }
            else 
                dp[i] = dp[i - 1];
        }
        
        return dp[n];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();