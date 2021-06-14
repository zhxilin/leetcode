//1854. Maximum Population Year
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int result = INT_MAX, maxPop = INT_MIN;
        
        for (int i = 1950; i <= 2050; ++i) {
            int pop = 0;
            for (auto log : logs) {
                int birth = log[0], death = log[1];
                
                if (i >= birth && i < death) {
                    pop++;
                    if (pop > maxPop) {
                        maxPop = pop;
                        result = i;
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
}();