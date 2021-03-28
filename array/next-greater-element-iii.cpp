//556. Next Greater Element III
class Solution {
public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        
        bool hasNext = nextPermutation(nums);
        
        size_t num = stoll(nums);
        
        return (!hasNext || num > INT_MAX) ? -1 : num;
    }

private:
    bool nextPermutation(string& nums) {
        //std::next_permutation简易实现
        int i = nums.size() - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }
        
        if (i == 0) 
            return false;
        
        int j = nums.size() - 1;
        while (j > 0 && nums[j] <= nums[i - 1]) {
            j--;
        }
        
        swap(nums[j], nums[i - 1]);
        reverse(nums.begin() + i, nums.end());
        
        return true;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();