//1021. Remove Outermost Parentheses
class Solution {
public:
    string removeOuterParentheses(string S) {
        stringstream ss;
        int cnt = 0;
        for (char& c : S) {
            if (c == '(' && ++cnt != 1)
                ss << c;
            if (c == ')' && --cnt != 0)
                ss << c;
        }
        return ss.str();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();