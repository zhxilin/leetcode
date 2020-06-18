//1304. Find N Unique Integers Sum up to Zero
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n, 0);
		
        for (int i = 0; i < n - 1; ++i) {
            result[i] = -1 * (i + 1);
            result[n-1] += i + 1;
        }
        return result;
    }
};