//1605. Find Valid Matrix Given Row and Column Sums
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> result(m, vector<int>(n));
        
        int i = 0, j = 0;
		while (i < m && j < n) {
			if (rowSum[i] < colSum[j]) {
				result[i][j] = rowSum[i];
				colSum[j] -= rowSum[i];
				rowSum[i] = 0;
                i++;
			} else {
				result[i][j] = colSum[j];
				rowSum[i] -= colSum[j];
				colSum[j] = 0;
                j++;
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