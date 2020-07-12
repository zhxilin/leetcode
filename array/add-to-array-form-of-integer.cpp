//989. Add to Array-Form of Integer
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int i = A.size();
        
        vector<int> result;
        int cur = K;
        while (--i >= 0 || cur) {
            if (i >= 0)
                cur += A[i];
            result.push_back(cur % 10);
            cur /= 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();