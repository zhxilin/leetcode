//693. Binary Number with Alternating Bits
class Solution {
public:
    bool hasAlternatingBits(int n) {
        //    1010101
        //+    101010
        //--------------
        //    1111111
        //&  10000000
        //--------------
        //   00000000  == 0 --> ok

        //      1011
        //+      101
        //---------------
        //     10000
        //&    10001
        //---------------
        //     10000    != 0 ---> not ok

        unsigned int temp = (unsigned int)(n >> 1) + n;
        return ((unsigned int)temp & (unsigned int)(temp + 1)) == 0;
    }:
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();