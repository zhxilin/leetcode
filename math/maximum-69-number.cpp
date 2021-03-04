//1323. Maximum 69 Number
class Solution {
public:
    int maximum69Number (int num) {
        
        vector<int> digits;
        
        while (num) {
            digits.insert(digits.begin(), num % 10);
            num /= 10;
        }
        
        //将第1个6改为9则该数一定最大
        for (auto& d : digits) {
            if (d == 6) {
                d = 9;
                break;
            }
        }
        
        int result = 0;
        int step = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            result += digits[i] * step;
            step *= 10;
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