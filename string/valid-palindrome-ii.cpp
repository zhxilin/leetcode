//680. Valid Palindrome II
class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.size() - 1;

        while (start < end) {
            if (s[start] != s[end]) {
                return check(s, start + 1, end) || check(s, start, end - 1);
            }

            start++;
            end--;
        }

        return true;
    }

private:
    bool check(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;

            start++;
            end--;
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