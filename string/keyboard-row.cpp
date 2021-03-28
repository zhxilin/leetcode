//500. Keyboard Row
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> s1 {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
            s2 {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
            s3 {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        
        auto check = [](const string& word, const unordered_set<char>& set) -> bool {
            for (auto& c : word) {
                if (!set.count(tolower(c)))
                    return false;
            }
            return true;
        };
        
        vector<string> result;
        for (const string& word : words) {
            if (check(word, s1) || check(word, s2) || check(word, s3))
                result.push_back(word);
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