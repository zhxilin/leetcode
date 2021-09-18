//1935. Maximum Number of Words You Can Type
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> brokens;
        for (char c : brokenLetters) {
            brokens.insert(c);
        }

        int result = 0, count = 0;

        for (int i = 0; i < text.size(); ++i) {
            if (text[i] == ' ') {
                if (count == 0)
                    result++;

                count = 0;
                continue;
            }

            if (brokens.count(text[i]))
                count++;
        }

        if (!count)
            result++;//last word

        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();