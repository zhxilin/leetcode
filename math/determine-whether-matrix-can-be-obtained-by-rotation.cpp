//1886. Determine Whether Matrix Can Be Obtained By Rotation
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target)
            return true;
        
        //分别旋转90、180、270度
        for (int i = 0; i < 3; ++i) {
            rotateMatrix(mat);
            if (mat == target)
                return true;
        }
        
        return false;
    }

private:
    void rotateMatrix(vector<vector<int>>& mat) {
        //旋转矩阵步骤:
        //1.矩阵转置
        //2.矩阵求逆
        int n = mat.size();
        
        for (int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {                
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        for(int i = 0; i < n; ++i) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();