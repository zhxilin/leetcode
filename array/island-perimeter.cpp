//463. Island Perimeter
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int result = 0;
        //Traversal order: up to bottom, left to right.
        //1.Each land increase by 4.
        //2.If top one is land too, decrease by 2, 
        //which represents the bottom edge of the top one and the top edge of the current one.
        //3.If left one is land too, decrease by 2, 
        //whichi represents the right edge of the left one and the left edge of the current one.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j])
                    continue;
                
                result += 4;
                //check up block
                if (i > 0 && grid[i - 1][j])
                    result -= 2;
                
                //check left block
                if (j > 0 && grid[i][j - 1])
                    result -= 2;
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