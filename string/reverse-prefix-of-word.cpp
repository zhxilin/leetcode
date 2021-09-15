//2000. Reverse Prefix of Word
class Solution {
public:
    string reversePrefix(string word, char ch) {
        reverse(word.begin(), word.begin() + word.find(ch) + 1);
        return word;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();