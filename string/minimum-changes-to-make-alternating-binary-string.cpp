//1758. Minimum Changes To Make Alternating Binary String
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int result = 0;
        
        int r1 = 0, r2 = 0;
        for (int i = 0; i < n; ++i) {
            r1 += i % 2 == 0 ? s[i] != '0' : s[i] != '1';
            r2 += i % 2 == 0 ? s[i] != '1' : s[i] != '0';
        }
        result = min(r1, r2);
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();