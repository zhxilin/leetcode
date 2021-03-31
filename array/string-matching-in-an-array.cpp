//1408. String Matching in an Array
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || words[i].size() > words[j].size()) 
                    continue;
                
                if (string::npos != words[j].find(words[i])) {
                    result.push_back(words[i]);
                    break;
                }
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
};