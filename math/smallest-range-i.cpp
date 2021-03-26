//908. Smallest Range I
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        //使max(B) - min(B)最小化 
        //==> 令max(B)最小,而min(B)最大 
        //==> max(B) = max(A) - K, min(B) = min(A) + K
        //==> max(B) - min(B) = (max(A) - K) - (min(A) + K) = max(A) - min(A) - 2 * K
        
        int maxA = INT_MIN, minA = INT_MAX;
        for (int a : A) {
            maxA = max(maxA, a);
            minA = min(minA, a);
        }
        
        return max(0, maxA - minA - 2 * K);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();