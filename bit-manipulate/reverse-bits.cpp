//190. Reverse Bits
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
     
        int i = 32;
        
        while (i--) {
            result <<= 1;

            if (n & 1 == 1)
                result ^= 1;

            n >>= 1;
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