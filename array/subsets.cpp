//78. Subsets
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        
        int n = nums.size();
        
        int len = 1 << n;
        //bitmask
        for (int mask = 0; mask < len; ++mask) {
            vector<int> v;
            for (int j = 0; j < n; ++j) {
                if (mask & 1 << j)
                    v.push_back(nums[j]);
            }
            result.push_back(v);
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