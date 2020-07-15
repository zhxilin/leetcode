//219. Contains Duplicate II
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mx;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (mx.count(nums[i]) && abs(mx[nums[i]] - i) <= k)
                return true;
            mx[nums[i]] = i;
        }
        
        return false;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();