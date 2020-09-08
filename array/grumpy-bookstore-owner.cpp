//1052. Grumpy Bookstore Owner
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        //用滑动窗口计算X分钟内，顾客数最多的窗口
        int normal = 0, win = 0, maxWin = 0;
        
        for (int i = 0; i < customers.size(); ++i) {
            normal += grumpy[i] == 0 ? customers[i] : 0;
            
            win += customers[i] * grumpy[i];
            
            if (i >= X) 
                win -= customers[i - X] * grumpy[i - X];
            
            maxWin = max(maxWin, win);
        }

        return normal + maxWin;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();