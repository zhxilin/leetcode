//1876. Substrings of Size Three with Distinct Characters
class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        if (n < 3) return 0;
        
        int i = 0, j = 0;
        int result = 0;
        
        while (j < n) {
            if (j - i + 1 == 3) {
                if (s[i] != s[i + 1] && s[i + 1] != s[j] && s[i] != s[j])
                    result++;
                
                i++;
            }
            j++;
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