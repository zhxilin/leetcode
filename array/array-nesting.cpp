//565. Array Nesting
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int result = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == INT_MAX)
                continue;
            
            int index = nums[i], count = 0;
            while (nums[index] != INT_MAX) {
                int tmp = index;
                index = nums[index];
                count++;
                nums[tmp] = INT_MAX;
            }
            
            result = max(result, count);
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