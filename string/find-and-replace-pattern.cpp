//890. Find and Replace Pattern
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        
        for (const string& word : words) {
            if (isPattern(word, pattern))
                result.push_back(word);
        }
        
        return result;
    }

private:
    bool isPattern(const string& word, const string& pattern) {
        unordered_map<char, char> mx;
        unordered_set<char> used;
        
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            char w = word[i], p = pattern[i];
            if (mx.count(p) && mx[p] != w || !mx.count(p) && used.count(w))
                return false;
            
            mx[p] = w;
            used.insert(w);
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