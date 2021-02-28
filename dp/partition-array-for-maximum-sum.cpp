//1043. Partition Array for Maximum Sum
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        //dp[i]表示arr[0..i]的最大和
        vector<int> dp(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            
            int maxSubVal = INT_MIN;
            int maxSum = INT_MIN;
            for (int j = 1; j <= k && i - j >= 0; ++j) {
                maxSubVal = max(maxSubVal, arr[i - j]);
                maxSum = max(maxSum, dp[i - j] + maxSubVal * j);
            }
            
            dp[i] = maxSum;
        }
        
        return dp[n];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();