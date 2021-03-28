//1078. Occurrences After Bigram
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        string word;
        for (int i = 0; i < text.size(); ++i) {
            if (text[i] == ' ') {
                words.push_back(word);
                word.clear();
                continue;
            }
            word += text[i];
        }
        if (!word.empty())
            words.push_back(word);
        
        vector<string> result;
        for (int i = 2; i < words.size(); ++i) {
            if (words[i - 2] == first && words[i - 1] == second)
                result.push_back(words[i]);
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