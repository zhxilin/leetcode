//75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) return;
        
        int l = 0, m = 0, h = nums.size() - 1;
        
        while (m <= h) {
            if (nums[m] == 0)
                swap(nums[m++], nums[l++]);
            else if (nums[m] == 1)
                m++;
            else
                swap(nums[h--], nums[m]);
        }
    }
};

static auto _ =[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();