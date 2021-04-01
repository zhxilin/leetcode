//1446. Consecutive Characters
class Solution {
public:
    int maxPower(string s) {
        int result = 0;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            int len = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] != s[i])
                    break;
                len++;
            }
                        
            result = max(result, len);
        }
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;  
};