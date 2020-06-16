//1252. Cells with Odd Values in a Matrix
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> col(m);
		vector<int> row(n);
		for (const vector<int>& indice: indices)
		{
			row[indice[0]]++;
			col[indice[1]]++;
		}
        
        int result = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				result += 1 == (row[i] + col[j]) % 2;
			}
        }
        
		return result;
    }
};