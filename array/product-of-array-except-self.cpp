//238. Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        
        vector<int> result(size, 1);
        
        for (int i = 1; i < size; ++i) {
            result[i] = nums[i - 1] * result[i - 1];
        }
        
        int rightProduct = 1;
        for (int i = size - 1; i >= 0; --i) {
            result[i] = result[i] * rightProduct;
            rightProduct *= nums[i];
        }
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();