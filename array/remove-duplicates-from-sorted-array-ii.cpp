//80. Remove Duplicates from Sorted Array II
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        //以ptr为最新的有效下标
        int cnt = 1, ptr = 0, n = nums.size();
		
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                ptr++;
                nums[ptr] = nums[i];
                cnt = 1;
            } else if (cnt < 2) {
                ptr++;
                nums[ptr] = nums[i];
                cnt++;;                
            }
        }
        
        return ptr + 1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();