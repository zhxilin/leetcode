//807. Max Increase to Keep City Skyline
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<int> rowMax(n), colMax(n);
        //skyline即每行每列的最大值
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMax[i] = max(rowMax[i], grid[i][j]);                
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result += min(rowMax[i], colMax[j]) - grid[i][j];
            }
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