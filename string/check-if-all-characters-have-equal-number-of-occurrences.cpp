//1941. Check if All Characters Have Equal Number of Occurrences
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        if (s.empty())
            return true;

        unordered_map<char, int> mx;
        for (const char& c : s) {
            mx[c]++;
        }

        int cnt = mx[s[0]];

        for (auto& p : mx) {
            if (p.second != cnt)
                return false;
        }

        return true;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
};