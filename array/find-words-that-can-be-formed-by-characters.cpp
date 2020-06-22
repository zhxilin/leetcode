//1160. Find Words That Can Be Formed by Characters
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> counts(26);
        for (char c : chars) {
            counts[c - 'a']++;
        }
        
        int result = 0;
        for (const string& word : words) {
            vector<int> cur(26);
            bool bIsPassed = true;
            
            for (char c : word) {
                int ch = c - 'a';
                if (++cur[ch] > counts[ch]) {
                    bIsPassed = false;
                    break;
                }
            }
            
            if (bIsPassed)
                result += word.size();
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