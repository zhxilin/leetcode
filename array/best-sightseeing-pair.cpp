//1014. Best Sightseeing Pair
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int pre = 0, n = A.size();
        int result = 0;
        for (int i = 1; i < n; ++i) {
            result = max(result, A[pre] + A[i] + pre - i);
            
            if (A[i] + i > A[pre] + pre){
                pre = i;
            }
        }
        
        return result;
    }
};

static auto _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();