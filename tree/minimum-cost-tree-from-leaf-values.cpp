//1130. Minimum Cost Tree From Leaf Values
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        if (arr.empty()) return 0;
        
        int sum = 0;
        //贪心算法
        while (arr.size() > 1) {
            int minProduct = INT_MAX;
            int pos = -1;
            
            //每一步算出最小乘积后，剪除最小乘积的较小因子
            for (int i = 1; i < arr.size(); ++i) {
                int product = arr[i] * arr[i - 1];
                if (minProduct > product) {
                    minProduct = product;
                    pos = arr[i - 1] < arr[i] ? i - 1 : i;
                }
            }
            sum += minProduct;
            arr.erase(arr.begin() + pos);
        }
        
        return sum;
    }
};