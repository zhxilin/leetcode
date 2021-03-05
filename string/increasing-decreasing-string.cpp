//1370. Increasing Decreasing String
class Solution {
public:
    string sortString(string s) {
        map<char, int> cnts;
        for (auto& c : s) {
            cnts[c]++;
        }
        
        int n = s.size();
        string result;
        while (n != result.size()) {
            for (auto it = cnts.begin(); it != cnts.end(); ++it) {
                if (it->second) {
                    result += it->first;
                    it->second--;
                }
            }
            for (auto it = cnts.rbegin(); it != cnts.rend(); ++it) {
                if (it->second) {
                    result += it->first;
                    it->second--;
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
}();