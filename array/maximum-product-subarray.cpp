//152. Maximum Product Subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_dp(n), min_dp(n);
        
        max_dp[0] = min_dp[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0) {
                max_dp[i] = max(nums[i], nums[i] * min_dp[i - 1]);
                min_dp[i] = min(nums[i], nums[i] * max_dp[i - 1]);
            } else {
                max_dp[i] = max(nums[i], nums[i] * max_dp[i - 1]);
                min_dp[i] = min(nums[i], nums[i] * min_dp[i - 1]);
            }            
        }
        
        int result = INT_MIN;
        for (int val : max_dp) {
            result = max(result, val);
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