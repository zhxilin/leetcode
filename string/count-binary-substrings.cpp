//696. Count Binary Substrings
class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0, prev = 0, cur = 1;
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] != s[i]) {
                result += min(prev, cur);
                prev = cur;
                cur = 1;
            } else
                cur++;
        }
        
        result += min(prev, cur);
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();