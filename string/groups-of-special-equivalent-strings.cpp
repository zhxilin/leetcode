//893. Groups of Special-Equivalent Strings
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_map<string, int> cnts;
        
        for (auto& s : A) {
            int n = s.size();
            string es, os;
            
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0)
                    es += s[i];
                else
                    os += s[i];
            }
            
            sort(es.begin(), es.end());
            sort(os.begin(), os.end());
            
            s = os + es;
            cnts[s]++;
        }
        
        return cnts.size();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();