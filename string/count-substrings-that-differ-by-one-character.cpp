//1638. Count Substrings That Differ by One Character
class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size(), m = t.size();
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int count = 0;
                for(int k = 0; k + i < n && k + j < m; ++k) {
                    if (s[i + k] != t[j + k])
                        count++;
                    
                    if (count > 1)
                        break;
                    
                    result += count;
                }
            }
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