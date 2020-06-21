//1122. Relative Sort Array
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        const int MAXSIZE = 1001;
        vector<int> count(MAXSIZE);
        
        for (int a1 : arr1) {
            count[a1]++;
        }
        
        int index = 0;
        for (int a2 : arr2) {
            while (count[a2] > 0 ) {
                arr1[index++] = a2;
                count[a2]--;
            }
        }
        
        for (int i = 0; i < MAXSIZE; i++) {
            while (count[i] > 0) {
                arr1[index++] = i;
                count[i]--;
            }
        }
        
        return arr1;
    }
};