//1260. Shift 2D Grid
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        int total = m * n;
        k %= total;
        
        //将数组扁平化
        vector<int> arr;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                arr.push_back(grid[i][j]);
            }
        }
        
        for (int i = 0; i < total; ++i) {
            int row = ((k + i) / n) % m;
            int col = (k + i) % n;
                
            grid[row][col] = arr[i];
        }
        
        return grid;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();