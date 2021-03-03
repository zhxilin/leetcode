//1768. Merge Strings Alternately
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        
        stringstream ss;
        
        while (1) {
            if (i < word1.size()) {
                ss << word1[i];
                i++;
            }
            
            if (j < word2.size()) {
                ss << word2[j];
                j++;
            }
            
            if (i >= word1.size() && j >= word2.size())
                break;
        }
        
        return ss.str();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();