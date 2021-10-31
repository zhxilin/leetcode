//6. Zigzag Conversion
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        vector<string> rows(min(numRows, int(s.size())));
        
        int cur = 0;
        bool down = false;
        
        for (auto& c : s) {
            rows[cur] += c;
            if (cur == 0 || cur == numRows - 1)
                down = !down;
            cur += down ? 1 : -1;
        }
        
        string result;
        for (auto& row : rows)
            result += row;
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();