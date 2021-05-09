//455. Assign Cookies
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0, result = 0;
        
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                result++;
                i++;
            } 
            
            j++;
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