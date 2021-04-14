//1624. Largest Substring Between Two Equal Characters
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<pair<int, int>> vec(26);
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (vec[c].first <= 0)
                vec[c].first = i + 1;
            else if (vec[c].second <= i + 1)
                vec[c].second = i + 1;
        }
        
        int result = -1;
        for (auto p : vec) {
            if (p.first != 0 && p.second != 0)
                result = max(result, p.second - p.first - 1);
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