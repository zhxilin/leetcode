//1816. Truncate Sentence
class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = 0;
        string result;
        
        for (int i = 0; i < s.length(); i++) {            
            if (s[i] == ' ') {
                count++;
            }
            
            if (count == k)
                break;
            
            result += s[i];
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