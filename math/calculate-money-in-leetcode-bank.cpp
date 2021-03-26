//1716. Calculate Money in Leetcode Bank
class Solution {
public:
    int totalMoney(int n) {
        int result = 0;
        int money = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 7 == 0)
                money = i / 7 + 1;
            else
                money++;
            
            result += money;
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