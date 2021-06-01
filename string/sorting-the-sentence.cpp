//1859. Sorting the Sentence
class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(9);
        
        string word, num;
        
        for (int i = 0; i <= s.size(); ++i) {
            if (s[i] == ' ' || i == s.size()) {
                int index = stoi(num) - 1;
                words[index] = word;
                num = "";
                word = "";
                continue;
            }
            
            if (isdigit(s[i]))
                num += s[i];
            else
                word += s[i];
        }
        
        string result;
        for (auto word : words) {
            if (word.empty())
                continue;
            
            if (!result.empty())
                result += ' ';
            result += word;
        }
        
        return result;
    }
};