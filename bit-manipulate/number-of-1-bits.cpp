//191. Number of 1 Bits
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            n &= (n - 1);
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