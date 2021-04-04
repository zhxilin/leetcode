//861. Score After Flipping Matrix
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        
        //先按行遍历,若每一行首列为0,则翻转行,使得每行首列为1,才可能最大化行值
        for (int i = 0; i < m; ++i) {
            if (!A[i][0])
                flipRow(A, i);
        }
        
        //再按列遍历,若每列0数量大于一半,则翻转列,使得1数量尽量多
        for (int j = 1; j < n; ++j) {
            int zeroCnt = 0;
            for (int i = 0; i < m; ++i) {
                if (!A[i][j])
                    zeroCnt++;
            }
            
            if (zeroCnt > m / 2)
                flipCol(A, j);
        }
        
        //求和
        int result = 0;
        for (int i = 0; i < m; ++i) {
            int value = 0;
            for (int j = 0; j < n; ++j) {
                value <<= 1;
                value |= A[i][j];
            }
            result += value;
        }
        
        return result;
    }

private:
    void flipRow(vector<vector<int>>& A, int row) {
        int n = A[0].size();
        for (int j = 0; j < n; ++j) {
            A[row][j] = !A[row][j];
        }
    }
    
    void flipCol(vector<vector<int>>& A, int col) {
        int m = A.size();
        for (int i = 0; i < m; ++i) {
            A[i][col] = !A[i][col];
        }
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();