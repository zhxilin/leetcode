//414. Third Maximum Number
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= first) {
                if (first == nums[i])
                    continue;
                
                third = second;
                second = first;
                first = nums[i];
            }
            else if (nums[i] >= second) {
                if (second == nums[i]) 
                    continue;
                
                third = second;
                second = nums[i];
            }
            else if (nums[i] >= third)
                third = nums[i];
        }
        
        return third == LONG_MIN ? first : third;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();