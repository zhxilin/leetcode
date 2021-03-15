//821. Shortest Distance to a Character
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> result(n);
        
        int prev = INT_MIN / 2;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == c)
                prev = i;
            result[i] = i - prev;
        }
        
        prev = INT_MAX / 2;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c)
                prev = i;
            result[i] = min(result[i], prev - i);
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