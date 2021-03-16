//883. Projection Area of 3D Shapes
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            int bestRow = 0, bestCol = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0)
                    result++;
                
                bestRow = max(bestRow, grid[i][j]);
                bestCol = max(bestCol, grid[j][i]);
            }
            result += bestRow + bestCol;
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