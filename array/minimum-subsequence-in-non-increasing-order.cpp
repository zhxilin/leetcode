//1403. Minimum Subsequence in Non-Increasing Order
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());       
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<int> result;
        int groupSum = 0;
        for (int i = 0; i < n; ++i) {
            groupSum += nums[n - i - 1];
            sum -= nums[n - i - 1];
            result.push_back(nums[n - i - 1]);
            if (sum < groupSum)
                break;
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