//561. Array Partition I
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int size = nums.size();
        for (int i = 0; i < size; i += 2) {
            result += nums[i];
        }
        return result;
    }
};

static auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();