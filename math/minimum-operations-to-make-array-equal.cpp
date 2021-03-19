//1551. Minimum Operations to Make Array Equal
class Solution {
public:
    int minOperations(int n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = 2 * i + 1;
        }
        
        int mid = v[n / 2];
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += abs(mid - v[i]);
        }
        
        return result / 2;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();