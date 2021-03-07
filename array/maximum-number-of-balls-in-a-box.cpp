//1742. Maximum Number of Balls in a Box
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        map<int, int> cnts;
        
        for (int i = lowLimit; i <= highLimit; ++i) {
            int n = i, sum = 0;
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            cnts[sum]++;
        }
        
        int result = 0;
        for (auto it = cnts.begin(); it != cnts.end(); ++it) {
            result = max(result, it->second);
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