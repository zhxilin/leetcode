//1646. Get Maximum in Generated Array
class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(n + 1);
        int result = 0;
        for (int i = 0; i <= n; ++i) {
            if (i < 2)
                nums[i] = i;
            else {
                if (i % 2 == 0)
                    nums[i] = nums[i / 2];
                else
                    nums[i] = nums[i / 2] + nums[i / 2 + 1];
            }
            result = max(result, nums[i]);
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