//136. Single Number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //x ^ x = 0
        //y ^ 0 = x
        //---> x ^ y ^ x = (x ^ x) ^ y = 0 ^ y = y
        //XOR all nums will get the single one.
        
        int result = 0;
        
        for (int num : nums) {
            result ^= num;
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