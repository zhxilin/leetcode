//1299. Replace Elements with Greatest Element on Right Side
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxValue = -1;
        vector<int> result(arr.begin(), arr.end());
        for (int i = arr.size() - 1; i >= 0; --i) {
            result[i] = maxValue;
            maxValue = max(maxValue, arr[i]);
        }
        return result;
    }
};