//1380. Lucky Numbers in a Matrix
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> rowMins;
        for (int row = 0; row < m; ++row) {
            int rowMin = INT_MAX;
            for (int col = 0; col < n; ++col) {
                rowMin = min(rowMin, matrix[row][col]);
            }
            rowMins.push_back(rowMin);
        }
        
        vector<int> result;
        for (int col = 0; col < n; ++col) {
            int colMax = INT_MIN;
            int targetRow = -1;
            for (int row = 0; row < m; ++row) {
                if (matrix[row][col] > colMax) {
                    colMax = matrix[row][col];
                    targetRow = row;
                }
            }
            
            if (targetRow != -1 && rowMins[targetRow] == colMax)
                result.push_back(colMax);
        }
        
        return result;
    }
};

static auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();