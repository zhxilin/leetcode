//1317. Convert Integer to the Sum of Two No-Zero Integers
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> result;
        
        for (int i = 1; i <= n; ++i) {
            int a = i, b = n - i;
            stringstream ss1, ss2;
            ss1 << a;
            ss2 << b;
            if (ss1.str().find('0') == string::npos && ss2.str().find('0') == string::npos) {
                result.push_back(a);
                result.push_back(b);
                break;
            }
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