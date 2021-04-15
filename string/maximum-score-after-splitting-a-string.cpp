//1422. Maximum Score After Splitting a String
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        //prefix sum
        vector<int> zeros(n + 1), ones(n + 1);
        for (int i = 0; i < n; ++i) {
            zeros[i + 1] = zeros[i] + (s[i] == '0');
            ones[i + 1] = ones[i] + (s[i] == '1');
        }
        
        int result = 0;
        for (int i = 1; i <= n - 1; ++i) {
            result = max(result, zeros[i] + ones[n] - ones[i]);
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