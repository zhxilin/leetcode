//521. Longest Uncommon Subsequence I
class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b)
            return -1;
        
        return max(a.size(), b.size());
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();