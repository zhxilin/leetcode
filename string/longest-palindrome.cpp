//409. Longest Palindrome
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> vec(128);
        
        for (auto c : s) {
            vec[c]++;
        }
        
        int result = 0;
        for (int cnt : vec) {
            result += cnt / 2 * 2;
            if (result % 2 == 0 && cnt % 2 == 1)
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