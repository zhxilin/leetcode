//1848. Minimum Distance to the Target Element
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int result = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != target)
                continue;
            
            int dist = abs(i - start);
            if (dist < result)
                result = dist;
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