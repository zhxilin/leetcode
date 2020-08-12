//1011. Capacity To Ship Packages Within D Days
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        
        //取值范围是所有元素的最大值，到所有元素之和，通过二分法求解最值
        
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        int n = weights.size();
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            
            int sum = 0;
            int days = 1;
            for(int i = 0; i < n; ++i) {
                sum += weights[i];
                if (sum > mid) {
                    sum = weights[i];
                    days++;
                }
            }
            
            if (days > D)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();