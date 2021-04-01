//1752. Check if Array Is Sorted and Rotated
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
        int x = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                x = i;
                break;
            }
        }
        
        vector<int> order(nums);
        sort(order.begin(), order.end());

        for (int i = 0; i < n; ++i) {
            if (order[i] != nums[(i + x) % n])
                return false;
        }

        return true;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;  
};