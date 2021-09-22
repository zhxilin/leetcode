//125. Valid Palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;

        while (l < r) {
            if (!isalnum(s[l]))
                l++;
            else if (!isalnum(s[r]))
                r--;
            else if (tolower(s[l]) != tolower(s[r]))
                return false;
            else {
                l++;
                r--;
            }
        }

        return true;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();