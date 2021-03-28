//476. Number Complement
class Solution {
public:
    int findComplement(int num) {
        unsigned int bits = floor(log2(num)) + 1;
        return ((unsigned int)(1 << bits) - 1) ^ num;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();