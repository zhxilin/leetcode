//1967. Number of Strings That Appear as Substrings in Word
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int result = 0;
        for (const auto& pattern : patterns) {
            if (std::string::npos != word.find(pattern))
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
};