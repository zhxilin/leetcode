//748. Shortest Completing Word
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cnts(26);
        for (auto c : licensePlate) {
            if (isalpha(c))
                cnts[tolower(c) - 'a']++;
        }
        
        string result;
        for (auto word : words) {
            vector<int> tmp(26);
            for (auto c : word) {
                if (isalpha(c))
                    tmp[tolower(c) - 'a']++;
            }
            
            int i = 0;
            for (; i < 26; ++i) {
                if (cnts[i] > tmp[i])
                    break;
            }
            
            if (i != 26)
                continue;
            
            if (result.empty() || result.size() > word.size())
                result = word;
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