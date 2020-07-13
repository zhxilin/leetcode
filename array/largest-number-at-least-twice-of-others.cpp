//747. Largest Number At Least Twice of Others
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int result = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (maxVal == nums[i]) {
                result = i;
                continue;
            }
            
            if (nums[i] * 2 > maxVal)
                return -1;
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