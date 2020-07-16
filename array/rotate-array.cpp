//189. Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //n=7, k=3
        //原始        1 2 3 4 5 6 7
        //翻转全部     7 6 5 4 3 2 1
        //翻转前k      5 6 7 4 3 2 1
        //翻转后n-k    5 6 7 1 2 3 4 -> 结果
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
    
private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            nums[start] ^= nums[end];
            nums[end] ^= nums[start];
            nums[start] ^= nums[end];
            
            start++;
            end--;
        }
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();