//1844. Replace All Digits with Characters
class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.size(); i += 2) {
            int digit = s[i] - '0';
            s[i] = char(s[i - 1] + digit);
        }
        return s;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();