//695. Max Area of Island
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n));
        
        int result = 0;
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y)
                result = max(result, dfs(x, y, grid, visited));
        }
        
        return result;
    }
    
private:
    
    int dfs(int x, int y, const vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int m = grid.size(), n = grid[0].size();
        
        if (x < 0 || x >= m || y < 0 || y >= n)
            return 0;
        
        if (!grid[x][y])
            return 0;
        
        if (visited[x][y])
            return 0;
        
        visited[x][y] = 1;
        
        return 1 + 
            dfs(x + 1, y, grid, visited) + 
            dfs(x - 1, y, grid, visited) + 
            dfs(x, y + 1, grid, visited) + 
            dfs(x, y - 1, grid, visited);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();