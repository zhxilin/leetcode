//674. Longest Continuous Increasing Subsequence
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        int result = INT_MIN;
        int len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1])
                len++;
            else
                len = 1;
            
            result = max(result, len);
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