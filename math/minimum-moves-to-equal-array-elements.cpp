//453. Minimum Moves to Equal Array Element
class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int min = nums[0];
        
        int result = 0;
        for (int n : nums) {
            result += n - min;
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