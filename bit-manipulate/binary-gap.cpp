//868. Binary Gap
class Solution {
public:
    int binaryGap(int n) {
        int result = 0;
        int len = -1;
        bool start = false;
        while (n) {
            int c = n % 2;
            if (start)
                len++;
            if (c == 1) {
                start = true;
                result = max(result, len);
                len = 0;
            }
            
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