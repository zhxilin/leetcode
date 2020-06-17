//1351. Count Negative Numbers in a Sorted Matrix
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        int row = m - 1, col = 0;
        int result = 0;
        
        while (row >= 0 && col < n) {
            if (grid[row][col] < 0) {
                result += n - col;
                row--;
            } else
                col++;
        }
        
        return result;
    }
};

static auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();