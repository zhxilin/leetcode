//581. Shortest Unsorted Continuous Subarray
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxVal = INT_MIN, minVal = INT_MAX;
        
        int start = 0, end = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            maxVal = max(maxVal, nums[i]);
            if (maxVal > nums[i])
                end = i;
        }
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            minVal = min(minVal, nums[i]);
            if (minVal < nums[i])
                start = i;
        }
        
        return end == start ? 0 : end - start + 1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();