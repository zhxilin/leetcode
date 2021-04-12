//976. Largest Perimeter Triangle
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        //形成三角形条件:任意两边之和大于第三边
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n - 3; i >= 0; --i) {
            if (nums[i] + nums[i + 1] > nums[i + 2])
                return nums[i] + nums[i + 1] + nums[i + 2];
        }
        
        return 0;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();