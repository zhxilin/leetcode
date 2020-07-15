//840. Magic Squares In Grid
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                if (isMagic(grid, i, j)) 
                    result++;
            }
        }
        return result;
    }

private:
    bool isMagic(vector<vector<int>>& grid, int i, int j) {
        vector<int> vec(16, 0);
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                vec[grid[i + r][j + c]] = 1;
            }
        }
        
        for (int i = 1; i <= 9; ++i) {
            if (!vec[i]) 
                return false;
        }
        
        int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2]; //取第一行的和为比较标准
        
        for (int k = 0; k < 3; ++k) {
            int rowSum = grid[i + k][j] + grid[i + k][j + 1] + grid[i + k][j + 2]; //行和
            int colSum = grid[i][j + k] + grid[i + 1][j + k] + grid[i + 2][j + k]; //列和
            if (rowSum != sum || colSum != sum) 
                return false;
        }
        
        int dgnSum1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2]; //对角和
        int dgnSum2 = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2]; //对角和
        
        if (dgnSum1 != sum || dgnSum2 != sum) 
            return false;
        
        return true;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();