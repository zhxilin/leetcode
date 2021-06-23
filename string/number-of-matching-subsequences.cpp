//792. Number of Matching Subsequences
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int result = 0;
        
        unordered_map<string, int> mx;
        
        for (string word : words) {
            if (!mx.count(word))               
                mx[word] = isSubseq(word, s);
            
            result += mx[word];
        }
        
        return result;
    }

private:
    bool isSubseq(const string& s, const string& t) {        
        if (s.size() > t.size()|| t.empty() && !s.empty()) 
            return false;
        
        if (s.empty()) 
            return true;
        
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            }
            else 
                j++;
        }
        
        return i == s.size();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();