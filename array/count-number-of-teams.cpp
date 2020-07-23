//1395. Count Number of Teams
class Solution {
public:
    int numTeams(vector<int>& rating) {
        if (rating.empty()) return 0;
        
        int result = 0;
        
        int size = rating.size();
        
        for (int i = 1; i < size - 1; ++i) {
            int l = 0, r = 0;
            for (int j = 0; j < i; ++ j) {
                if (rating[j] > rating[i])
                    ++l;
            }
            
            for (int j = i + 1; j < size; ++j) {
                if (rating[j] > rating[i])
                    ++r;
            }
            
            result += l * (size - (i + 1) - r) + (i - l) * r;
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