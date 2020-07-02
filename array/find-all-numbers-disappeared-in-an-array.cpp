//448. Find All Numbers Disappeared in an Array
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;
        
        for (int i = 0; i < size; ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0)
                nums[index] = -nums[index];
        }
        
        for (int i = 0; i < size; ++i) {
            if (nums[i] > 0)
                result.push_back(i + 1);
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