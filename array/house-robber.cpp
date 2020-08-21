//198. House Robber
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int n = nums.size();
        vector<int> dp(n);
        
        for(int i = 0; i < n; ++i) {
            dp[i] = max(nums[i] + ((i >= 2) ? dp[i - 2] : 0), (i >= 1) ? dp[i - 1] : 0);
        }
        
        return dp[n - 1];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();