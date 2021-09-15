//1877. Minimize Maximum Pair Sum in Array
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int result = INT_MIN;
        for (int i = 0; i < n / 2; ++i) {
            int sum = nums[i] + nums[n - i - 1];
            if (sum > result)
                result = sum;
        }

        return result;
    }
};


static auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();