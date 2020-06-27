//867. Transpose Matrix
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> t;
        
        for (int col = 0; col < n; ++col) {
            vector<int> tRow;
            for (int row = 0; row < m; ++row) {
                tRow.push_back(A[row][col]);
            }
            t.push_back(std::move(tRow));
        }
        
        return t;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();