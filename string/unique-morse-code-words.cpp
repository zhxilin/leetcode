//804. Unique Morse Code Words
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const vector<string> table {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        
        unordered_set<string> mx;
        for (auto& word : words) {
            stringstream ss;
            for (auto& c : word) {
                int index = c - 'a';
                ss << table[index];
            }
            mx.insert(ss.str());
        }
        
        return mx.size();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();