//1281. Subtract the Product and Sum of Digits of an Integer
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        
        while (n) {
            int mod = n % 10;
            product *= mod;
            sum += mod;
            n /= 10;
        }
        
        return product - sum;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();