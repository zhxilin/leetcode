//704. Binary Search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        
        while (low < high) {
            int mid = low + (high - low - 1) / 2;
            
            if (nums[mid] > target)
                high = mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] == target) 
                return mid;
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