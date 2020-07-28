//1329. Sort the Matrix Diagonally
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        //左下三角
        for (int i = 0; i < m; ++i)
            sortDiagonal(mat, i, 0);
        
        //右上三角
        for (int i = 0; i < n; ++i)
            sortDiagonal(mat, 0, i);
        
        return mat;
    }

private:
    void sortDiagonal(vector<vector<int>>& mat, int row, int col) {
        int m = mat.size(), n = mat[0].size();
       
        //row和col斜线代表起始位置        
        vector<int> tmp;
        int i = row, j = col;
        
        //斜线排序
        while (i < m && j < n)
            tmp.push_back(mat[i++][j++]);
        
        std::sort(tmp.begin(), tmp.end());
        
        //写回原矩阵
        i = row, j = col; 
        int k = 0;
        while (i < m && j < n)
            mat[i++][j++] = tmp[k++];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();