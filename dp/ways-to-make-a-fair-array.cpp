//1664. Ways to Make a Fair Array
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        
        //prefix sum
        vector<int> preEven(n + 1), preOdd(n + 1);
        
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                preEven[i + 1] = preEven[i] + nums[i];
                preOdd[i + 1] = preOdd[i];
            } else {
                preEven[i + 1] = preEven[i];
                preOdd[i + 1] = preOdd[i] + nums[i];
            }
        }
        
        int result = 0;
        for (int i = 1; i < n + 1; ++i) {
            //移除位置的前序和奇偶不变
            int es1 = preEven[i - 1];
            int os1 = preOdd[i - 1];
            //移除位置的后续和奇偶相反
            int es2 = preOdd[n] - preOdd[i];
            int os2 = preEven[n] - preEven[i];
            
            if (es1 + es2 == os1 + os2)
                result++;
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