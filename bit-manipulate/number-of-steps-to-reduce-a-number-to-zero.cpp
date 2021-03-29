//1342. Number of Steps to Reduce a Number to Zero
class Solution {
public:
    int numberOfSteps (int num) {
        int result = 0;
        
        while (num) {
            if (num % 2 == 0) 
                num >>= 1;
            else
                num -= 1;
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