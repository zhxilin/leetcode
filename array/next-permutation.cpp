//31. Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {        
        int i = nums.size() - 2;
        
        //1.从右往左找到第一个降序的位置i
        while (i >= 0 && nums[i + 1] <= nums[i])
            --i;
        
        //2.从右往该位置,找到首个大于该位置i的值的位置j,并交换两个位置的值
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i])
                --j;
            
            nums[i] ^= nums[j];
            nums[j] ^= nums[i];
            nums[i] ^= nums[j];
        }
        
        //3.从位置i+1到末尾逆序
        reverse(nums.begin() + i + 1, nums.end());
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();