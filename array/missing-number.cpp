//268. Missing Number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int expectedSum = size * (size + 1) / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return expectedSum - sum;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();