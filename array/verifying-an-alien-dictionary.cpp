//953. Verifying an Alien Dictionary
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> vec(26);
        for (int i = 0; i < order.size(); ++i) {
            vec[order[i] - 'a'] = i;
        }
        
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (j >= words[i + 1].size())
                    return false;
                
                if (words[i][j] != words[i + 1][j]) {
                    if (vec[words[i][j] - 'a'] > vec[words[i + 1][j] - 'a'])
                        return false;
                    else
                        break;
                }
            }
        }
        
        return true;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();