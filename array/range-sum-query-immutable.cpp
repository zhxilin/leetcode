//303. Range Sum Query - Immutable
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        dp = nums;
        for (int i = 1; i < n; ++i)
            dp[i] += dp[i - 1];
    }
    
    int sumRange(int i, int j) {
        if (i == 0) 
            return dp[j];
        
        return dp[j] - dp[i - 1];
    }

private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

static auto _ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();