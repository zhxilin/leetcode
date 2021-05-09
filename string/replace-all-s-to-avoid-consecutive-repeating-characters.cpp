//1576. Replace All ?'s to Avoid Consecutive Repeating Characters
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                char l = i - 1 < 0 ? '?' : s[i - 1];
                char r = i + 1 >= n ? '?' : s[i + 1];
                s[i] = replaceMark(l, r);
            }
        }
        return s;
    }
    
private:
    char replaceMark(char l, char r) {
        for (char c = 'a'; c <= 'c'; ++c) {
            if (c != l && c != r)
                return c;
        }
        return '?';
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();