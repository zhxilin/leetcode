//1347. Minimum Number of Steps to Make Two Strings Anagram
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> mx(26);
        for (char c : s) {
            mx[c - 'a']++;
        }
        
        int result = 0;
        for (char c : t) {
            if (mx[c - 'a'])
                mx[c - 'a']--;
            else
                result++;
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