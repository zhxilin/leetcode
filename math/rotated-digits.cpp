//788. Rotated Digits
class Solution {
public:
    int rotatedDigits(int N) {
        unordered_map<int, int> mx {
            {0, 0},
            {1, 1},
            {2, 5},
            {5, 2},
            {6, 9},
            {8, 8},
            {9, 6}
        };
        
        int result = 0;
        for (int i = 1; i <= N; ++i) {
            int num = i;
            int rotate = 0;
            int adv = 1;
            while (num) {
                int digit = num % 10;
                
                if (!mx.count(digit)) {
                    rotate = 0;
                    break;
                }
                
                rotate += mx[digit] * adv;
                adv *= 10;
                
                num /= 10;
            }
            
            if (rotate != 0 && i != rotate)
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