//520. Detect Capital
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() < 2)
            return true;
        
        bool result = true;
        char c1 = word[0], c2 = word[1];
        int n = word.size();
        
        auto islower = [](char c) { return c >= 'a' && c <= 'z'; };
        auto isupper = [](char c) { return c >= 'A' && c <= 'Z'; };
        
        if (isupper(c1) && isupper(c2)) {
            //case 1
            for (int i = 2; i < n; ++i) {
                if (islower(word[i])) 
                    return false;
            }
            
        } else {
            //case 2/3
            for (int i = 1; i < n; ++i) {
                if (isupper(word[i])) 
                    return false;
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