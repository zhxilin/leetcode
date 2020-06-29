//896. Monotonic Array
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() <= 1) return true;
        
        bool increasing = A[0] <= A[A.size() - 1];
        for (int i = 1; i < A.size();  ++i) {
            if (increasing) {
                if (A[i] < A[i - 1])
                    return false;
            } else {
                if (A[i] > A[i - 1])
                    return false;
            }
        }
        
        return true;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();