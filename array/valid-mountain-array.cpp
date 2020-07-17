//941. Valid Mountain Array
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int size = A.size();
        
        int i = 0;
        
        while (i < size - 1 && A[i] < A[i + 1])
            i++;
        
        if (i == 0 || i == size - 1)
            return false;
        
        while (i < size - 1 && A[i] > A[i + 1])
            i++;
        
        return i == size - 1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();