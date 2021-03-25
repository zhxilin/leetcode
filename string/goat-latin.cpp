//824. Goat Latin
class Solution {
public:
    string toGoatLatin(string S) {
        const unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};       
        string posfix("ma");
        
        vector<string> words = split(S, ' ');
        string result;
        for (auto& word : words) {
            posfix += "a";
            char c = word[0];
            if (vowels.count(c)) {
                word += posfix;
            } else {
                word.erase(word.begin());
                word += c + posfix;
            }
            if (!result.empty())
                result += " ";
            result += word;
        }
        return result;
    }

private:
    vector<string> split(const std::string &s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> elems;
        while (getline(ss, item, delim)) {
            elems.push_back(std::move(item));
        }
        return std::move(elems);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();