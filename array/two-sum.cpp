//1. Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mx;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (mx.count(complement))
                return {mx[complement], i};
            
            mx[nums[i]] = i;
        }
        
        return {};
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();