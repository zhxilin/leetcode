//128. Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mx(nums.begin(), nums.end());

        int result = 0;

        for (int num : mx) {
            if (mx.count(num - 1))
                continue;

            int curNum = num;
            int streak = 1;

            //实际上只有子序列开头判断成功才会执行一次，整体时间复杂度O(n + n) = O(n)
            while (mx.count(curNum + 1)) {
                curNum++;
                streak++;
            }

            result = max(result, streak);
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