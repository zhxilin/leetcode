//1913. Maximum Product Difference Between Two Pairs
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        if (n < 4)
            return 0;

        sort(nums.begin(), nums.end());

        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();