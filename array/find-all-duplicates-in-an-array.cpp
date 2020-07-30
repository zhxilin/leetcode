//442. Find All Duplicates in an Array
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            int pos = abs(nums[i]) - 1;
            
            if (nums[pos] > 0)
                nums[pos] *= -1;
            else
                result.push_back(pos + 1);
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