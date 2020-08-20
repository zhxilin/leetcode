//714. Best Time to Buy and Sell Stock with Transaction Fee
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<int> buyHold(n), profit(n);
        
        buyHold[0] = prices[0]; //持有股票的最低价格
        profit[0] = 0; //最大收益
        
        for (int i = 1; i < n; ++i) {
            buyHold[i] = min(prices[i] - profit[i - 1], buyHold[i - 1]);
            profit[i] = max(prices[i] - buyHold[i - 1] - fee, profit[i - 1]);
        } 
        
        return profit[n - 1];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();