//832. Flipping an Image
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int size = A.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; 2 * j < size; ++j) {
                int temp = A[i][j] ^ 1;
                A[i][j] = A[i][size - j - 1] ^ 1;
                A[i][size - j - 1] = temp;
            }
        }
        
        return A;
    }
};