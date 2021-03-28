//1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        
        string word;            
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') {
                words.push_back(word);
                word.clear();
                continue;
            }
            word += sentence[i];
        }
        
        if (!word.empty())            
            words.push_back(word);
        
        int result = -1;
        int len = searchWord.size();
        for (int i = 1; i <= words.size(); ++i) {
            if (words[i - 1].substr(0, len) == searchWord) {
                result = i;
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