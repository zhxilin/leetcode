//162. Find Peak Element
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        while (l < h) {
            int mid = (l + h) / 2;
            if (nums[mid] > nums[mid + 1])
                h = mid;
            else
                l = mid + 1;
        }
        
        return l;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();