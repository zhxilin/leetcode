//506. Relative Ranks
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> result(n);
        
        map<int, string, greater<int>> mx;
        for (int i = 0; i < n; ++i) {
            mx[score[i]] = ""; 
        }
        
        int place = 1;
        for (auto& p : mx) {
            if (1 == place)
                p.second = "Gold Medal";
            else if (2 == place)
                p.second = "Silver Medal";
            else if (3 == place)
                p.second = "Bronze Medal";
            else
                p.second = to_string(place);
            
            place++;
        }
        
        for (int i = 0; i < n; ++i) {
            result[i] = mx[score[i]];
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