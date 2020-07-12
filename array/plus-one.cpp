//66. Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return {1};
        
        int size = digits.size();
        vector<int> result;
        
        int cur = 1;
        int i = size;
        
        while (--i >= 0 || cur > 0) {
            if (i >= 0)
                cur += digits[i];
            
            result.push_back(cur % 10);
            cur /= 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();