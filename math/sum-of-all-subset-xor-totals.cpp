//1863. Sum of All Subset XOR Totals
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return allSubs(nums, 0, 0);
    }
    
private:
    int allSubs(vector<int>& nums, int cur, int tmp) {
        if (cur == nums.size())
            return tmp;
        
        int include = allSubs(nums, cur + 1, tmp ^ nums[cur]);
        int exclude = allSubs(nums, cur + 1, tmp);
        return include + exclude;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();