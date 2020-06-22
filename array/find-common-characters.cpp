//1002. Find Common Characters
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        
        const int size = A.size();
        vector<vector<int>> counts(size, vector<int>(26, 0));
        
        //统计每个单词每个字符的出现次数
        for (int i = 0; i < size; ++i) {
            for (char c : A[i]) {
                counts[i][c - 'a']++;
            }
        }        
        
        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            //每个字符在每个单词中出现的最少次数为公共次数
            int count = INT_MAX;
            
            for (int j = 0; j < size; ++j) {
                count = min(count, counts[j][i]);
            }
            
            for (int k = 0; k < count; ++k) {
                result.push_back(string(1, i + 'a'));
            }
        }
        
        return result;
    }
};

static auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();