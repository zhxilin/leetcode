//1508. Range Sum of Sorted Subarray Sums
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> presum(n + 1);        
        for (int i = 1; i < n + 1; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }

        vector<int> sums;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                sums.push_back(presum[j] - presum[i]);
            }
        }
        
        sort(sums.begin(), sums.end());
        
        long long result = 0;
        for (int i = left - 1; i < right; ++i) {
            result += sums[i];
        }
        
        return result % 1000000007;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();