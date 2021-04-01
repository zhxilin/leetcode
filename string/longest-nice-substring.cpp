//1763. Longest Nice Substring
class Solution {
public:
    string longestNiceSubstring(string s) {
        string result;
        int n = s.size();
        
        int maxlen = 0;
        for (int i = 0; i < n; ++i) {
            vector<bool> cnts(52);
            for (int j = i; j < n; ++j) {
                if (isupper(s[j]))
                    cnts[s[j] - 'A'] = true;
                else
                    cnts[s[j] - 'a' + 26] = true;
                
                int len = j - i + 1;
                if (len > maxlen) {
                    int k = 0;
                    for (; k < 26; ++k) {
                        if (cnts[k] != cnts[k + 26])
                            break;
                    }
                    if (k == 26) {
                        maxlen = len;
                        result = s.substr(i, maxlen);
                    }
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