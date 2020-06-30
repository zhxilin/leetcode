//122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int result = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1])
                result += prices[i] - prices[i - 1];
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