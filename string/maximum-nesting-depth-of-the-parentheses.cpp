//1614. Maximum Nesting Depth of the Parentheses
class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int depth = 0;
        
        //任意字符的深度 = 字符左侧所有“(”数量 - 字符左侧所有“)”数量
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                depth++;
                result = max(result, depth);
            }
            else if (s[i] == ')') 
                depth--;
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