//2006. Count Number of Pairs With Absolute Difference K
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();

        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int diff = nums[i] - nums[j];
                if (diff == k || diff == -k)
                    result++;
            }
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