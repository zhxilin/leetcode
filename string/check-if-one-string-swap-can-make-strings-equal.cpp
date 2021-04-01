//1790. Check if One String Swap Can Make Strings Equal
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<int> cnts(26);
        
        int diffCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i])
                diffCnt++;
            if (diffCnt > 2)
                return false;
            
            cnts[s1[i] - 'a']++;
            cnts[s2[i] - 'a']--;
        }
        
        for (int c : cnts) {
            if (c)
                return false;
        }
        
        return true;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;  
};