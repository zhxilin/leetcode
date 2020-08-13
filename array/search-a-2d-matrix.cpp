//74. Search a 2D Matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m <= 0) return false;
        
        int n = matrix[0].size();
        if (n <= 0) return false;
        
        int lr = 0, hr = m - 1;
        
        while (lr < hr) {
            int mid = (lr + hr) / 2;
            if (matrix[mid][n - 1] == target) return true;
            
            if (matrix[mid][n - 1] > target)
                hr = mid;
            else
                lr = mid + 1;
        }
        
        int lc = 0, hc = n;
        while (lc < hc) {
            int mid = (lc + hc) / 2;
            if (matrix[lr][mid] == target) return true;
            
            if (matrix[lr][mid] > target)
                hc = mid;
            else
                lc = mid + 1;
        }
        
        return false;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();