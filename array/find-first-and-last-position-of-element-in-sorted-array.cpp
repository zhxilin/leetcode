//34. Find First and Last Position of Element in Sorted Array
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lowIndex = search(nums, target, [](int v, int t) { return v >= t; });
        if (lowIndex == nums.size() || nums[lowIndex] != target)
            return {-1, -1};
        
        int highIndex = search(nums, target, [](int v, int t) { return v > t; }) - 1;
        
        return {lowIndex, highIndex};
    }
    
private:
    int search(vector<int>& nums, int target, std::function<bool(int, int)> op) {
        int low = 0, high = nums.size();
        
        while (low < high) {
            int mid = (low + high) / 2;
            if (op(nums[mid], target))
                high = mid;
            else
                low = mid + 1;
        }
        
        return low;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();