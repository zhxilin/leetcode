//153. Find Minimum in Rotated Sorted Array
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) 
            return nums[0];
        
        int l = 0, r = nums.size() - 1;
        if (nums[r] > nums[l])
            return nums[0];
        
        //二分查找，找到中点相邻元素出现转折的位置
        while (l <= r) {
            int mid = (l + r) / 2;
            
            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            
            if (nums[mid - 1] > nums[mid])
                return nums[mid];
            
            if (nums[mid] > nums[0])
                l = mid + 1;
            else
                r = mid + 1;
        }
        
        return -1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();