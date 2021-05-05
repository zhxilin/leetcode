//202. Happy Number
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> mx;
        
        while (n != 1) {
            if (mx.count(n))
                break;
            
            mx.insert(n);
            
            int sum = 0, tmp = n;
            
            while (tmp) {
                sum += pow(tmp % 10, 2);
                tmp /= 10;
            }
            
            n = sum;
        }
        
        return n == 1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();