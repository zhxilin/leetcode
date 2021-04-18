//1137. N-th Tribonacci Number
class Solution {
public:
    int tribonacci(int n) {
        vector<int> f(38);
        f[0] = 0, f[1] = 1, f[2] = 1;
        for (int i = 3; i <= n; ++i) {
            f[i] = f[i - 1] + f[i - 2] + f[i - 3];
        }
        return f[n];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();