//1684. Count the Number of Consistent Strings
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mx;
        for (int i = 0; i < allowed.size(); ++i) {
            mx[allowed[i]]++;
        }
        
        int result = 0;
        for (const std::string& word : words) {
            bool valid = true;
            for (int i = 0; i < word.size(); ++i) {
                if (!mx.count(word[i])) {
                    valid = false;
                    break;
                }  
            }
            if (valid)
                result++;
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