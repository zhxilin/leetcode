//121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        
        int result = 0;
        for (int price : prices) {
            if (price < minPrice)
                minPrice = price;
            else if (price - minPrice > result)
                result = price - minPrice;
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