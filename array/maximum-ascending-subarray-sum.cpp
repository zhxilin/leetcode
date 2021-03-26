//1800. Maximum Ascending Subarray Sum
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int result = 0;
        
        int n = nums.size();
        int sum = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                sum += nums[i];
            else {
                result = max(result, sum);
                sum = nums[i];
            }
        }
        
        result = max(result, sum);
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();