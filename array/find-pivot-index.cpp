//724. Find Pivot Index
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        int left = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (left == sum - left - nums[i])
                return i;
            left += nums[i];
        }
        
        return -1;
    }
};

static auto _= []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();