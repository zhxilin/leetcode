//26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int i = 0;
        
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] != nums[i]) i++;
            
            nums[i] = nums[j];
        }
        
        return i + 1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();