//495. Teemo Attacking
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        if (timeSeries.empty()) return 0;
        
        int n = timeSeries.size();
        
        int result = duration;
        for (int i = 0; i < n - 1; ++i) {
            result += min(timeSeries[i + 1] - timeSeries[i], duration);
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