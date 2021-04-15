//389. Find the Difference
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mx;
        for (auto c : s) {
            mx[c]++;
        }
        
        char result;
        for (auto c : t) {
            if (!mx.count(c)) {
                result = c;
                break;
            }
            
            mx[c]--;
            if (mx[c] < 0) {
                result = c;
                break;
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