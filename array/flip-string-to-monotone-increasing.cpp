//926. Flip String to Monotone Increasing
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();

        int d0 = 0; //使S[0, i)都变成'0'的最小步数
        int d1 = 0; //使S[0, i)变成开头一部分'0'且最后一位为'1'（甚至没有）的最小步数

        for (int i = 0; i < n; ++i) {
            d0 += S[i] == '1';
            d1 = min(d0, d1 + (S[i] == '0'));
        }
        return min(d0, d1);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
