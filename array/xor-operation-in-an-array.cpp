//1486. XOR Operation in an Array
class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            result ^= start + 2 * i;
        }
        
        return result;
     }
};

static auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();