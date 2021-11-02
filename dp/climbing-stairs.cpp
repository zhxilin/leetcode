//70. Climbing Stairs
class Solution {
public:
    int climbStairs(int n) {
        //at last only has 1-step or 2-steps way
        //if last take 1 step, there are f(n - 1) ways
        //if last take 2 steps, there are f(n - 2) ways
        //so f(n) = f(n - 1) + f(n - 2)
        //it is similar to a fibonacci sequence
        //climbing stairs: f(0) = 1, f(1) = 1, f(2) = 2
        //fibonacci sequence: f(0) = 0, f(1) = 1, f(2) = 1
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();