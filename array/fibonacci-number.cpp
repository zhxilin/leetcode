//509. Fibonacci Number
class Solution {
public:
    int fib(int N) {
        if (0 == N) return 0;
        if (1 == N) return 1;
        
        vector<int> dp(N + 1);
        
        dp [1] = dp[2] = 1;
        
        for (int i = 3; i <= N; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[N];
    }
};

static auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();