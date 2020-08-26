//1140. Stone Game II
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        vector<vector<int>> dp(101, vector<int>(101));
        vector<int> sum(101);
                
        //先求截止每个pile的累进和
        for (int i = n - 1; i >= 0; --i)
			sum[i] = piles[i] + sum[i + 1];
            
        //举例 [2,7,9,4,4]
        //Alex第一步有2种选择：选2个或者1个，不管哪种选择，都可以求解以下dfs
        //选中的所有元素之和 + dfs(新索引, 新m);
        //但由于dfs(新索引，新m)返回的是Lee的结果，因此可以用从新索引到结尾的元素之和，减去Lee返回的结果
        //即得到再下一次Alex的结果
        return dfs(dp, sum, n, 0, 1);
    }
    
private:
    int dfs(vector<vector<int>>& dp, const vector<int>& sum, int n, int i , int m) {
        if (i >= n) return 0;
        
        if (dp[i][m]) return dp[i][m];
        
        for (int j = 1; j <= 2 * m; ++j) {
            dp[i][m] = max(dp[i][m], sum[i] - dfs(dp, sum, n, i + j, max(j, m)));
        }
        
        return dp[i][m];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();