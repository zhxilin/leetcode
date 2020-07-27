//48. Rotate Image
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = i; j < cols; ++j) {
               swap(matrix[i][j], matrix[j][i]);
            }
        }
   
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();