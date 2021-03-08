//1207. Unique Number of Occurrences
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> cnts, cnts2;
        for (auto& v : arr) {
            cnts[v]++;
        }
        
        for (auto& p : cnts) {
            cnts2[p.second]++;
        }
        
        for (auto& p : cnts2) {
            if (p.second > 1)
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
}();