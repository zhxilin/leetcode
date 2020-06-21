//1385. Find the Distance Value Between Two Arrays
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int result = 0;
        
        for (int a1 : arr1) {
            bool bPassed = true;
            for (int a2 : arr2) {
                if (abs(a1 - a2) <= d) {
                    bPassed = false;
                    break;
                }
            }
            result += bPassed;
        }
        
        return result;
    }
};