//806. Number of Lines To Write String
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1, length = 0;
        for (int i = 0; i < s.size(); ++i) {
            int l = widths[ s[i] - 'a'];
            if (length + l <= 100)
                length += l;
            else {
                length = l;
                lines++;
            }
        }
        return {lines, length};
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();