//1827. Minimum Operations to Make the Array Increasing
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                continue;
            
            int diff = nums[i - 1] + 1 - nums[i];
            nums[i] = nums[i - 1] + 1;
            result += diff;
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