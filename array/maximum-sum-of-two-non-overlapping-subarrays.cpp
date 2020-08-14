//1031. Maximum Sum of Two Non-Overlapping Subarrays
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        return max(maxSum(A, L, M), maxSum(A, M, L));
    }

private:
    int maxSum(vector<int>& A, int L, int M) {
        int n = A.size();
        
        int maxSumM = 0;
        
        int sumL = 0, sumM = 0;
        
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            sumL += A[i];
            //滑动窗口
            if (i >= L) {
                sumL -= A[i - L];
                sumM += A[i - L];
            }
            
            if (i - L >= M)
                sumM -= A[i - L - M];
            
            maxSumM = max(maxSumM, sumM);
            
            result = max(result, sumL + maxSumM);      
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