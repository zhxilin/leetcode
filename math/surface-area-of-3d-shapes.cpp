//892. Surface Area of 3D Shapes
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int result = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] <= 0)
                    continue;
                
                //每个位置上下面各贡献1
                result += 2;
                
                //东南西北4个方向各贡献max(v - nv, 0), nv为各方向邻接块的高度
                //北
                result += max(grid[i][j] - (i > 0 ? grid[i - 1][j] : 0), 0);
                //东
                result += max(grid[i][j] - (j < n - 1 ? grid[i][j + 1] : 0), 0);
                //南
                result += max(grid[i][j] - (i < m - 1 ? grid[i + 1][j] : 0), 0);
                //西
                result += max(grid[i][j] - (j > 0 ? grid[i][j - 1] : 0), 0);
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