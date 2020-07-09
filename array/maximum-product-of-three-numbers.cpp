//628. Maximum Product of Three Numbers
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        int size = nums.size();
        
        if (nums[1] < 0 && nums[size - 1] > 0) {
            if ((nums[0] * nums[1]) > (nums[size - 1] * nums[size - 2]))
                return nums[0] * nums[1] * nums[size - 1];
            
            if ((nums[0] * nums[1]) > (nums[size - 2] * nums[size - 3]))
                return nums[0] * nums[1] * nums[size - 1];
        }
        return nums[size - 1] * nums[size - 2] * nums[size - 3];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();