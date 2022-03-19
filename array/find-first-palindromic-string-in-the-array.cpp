//2108. Find First Palindromic String in the Array
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto& word : words) {
            if (isPalindrome(word))
                return word;
        }

        return "";
    }

private:
    bool isPalindrome(const string& word) {
        int n = word.size();
        int start = 0, end = n - 1;

        while (start < end) {
            if (word[start] != word[end])
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