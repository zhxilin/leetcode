//1221. Split a String in Balanced Strings
class Solution {
public:
    int balancedStringSplit(string s) {
        int result = 0;
        int l = 0, r = 0;
        
        //greedy
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'L')
                l++;
            else
                r++;
            
            if (l == r) {
                l = r = 0;
                result++;
            }
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