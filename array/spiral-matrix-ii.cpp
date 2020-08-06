//59. Spiral Matrix II
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int c1 = 0, c2 = n - 1;
        int r1 = 0, r2 = n - 1;
        
        int num = 1;
        while (r1 <= r2 && c1 <= c2) {
            
            for (int c = c1; c <= c2; ++c)
                matrix[r1][c] = num++;
            r1++;
            
            for (int r = r1; r <= r2; ++r)
                matrix[r][c2] = num++;
            c2--;
            
            //注意仅剩一行和一列的情况
            if (r1 <= r2) {
                for (int c = c2; c >= c1; --c)
                    matrix[r2][c] = num++;
                r2--;
            }
              
            if (c1 <= c2) {
                for (int r = r2; r >= r1; --r)
                    matrix[r][c1] = num++;
                c1++;
            }
        }
        
        return matrix;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();