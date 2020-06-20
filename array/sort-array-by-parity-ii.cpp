//922. Sort Array By Parity II
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> result(A.size());
        int evenIndex = 0, oddIndex = 1;
        
        for (int num : A) {
            if (0 == num % 2) {
                result[evenIndex] = num;
                evenIndex += 2;
            } else {
                result[oddIndex] = num;
                oddIndex += 2;
            }
        }
        
        return result;
    }
};