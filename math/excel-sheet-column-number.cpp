//171. Excel Sheet Column Number
class Solution {
public:
    int titleToNumber(string columnTitle) {
        //26进制
        int result = 0;
        int n = columnTitle.size();
        
        for (int i = 0; i < n; ++i) {
            result += pow(26, n - i - 1) * (1 + (columnTitle[i] - 'A'));
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