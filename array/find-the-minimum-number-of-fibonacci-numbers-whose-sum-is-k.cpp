//1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        //生成最逼近k的斐波那契数，然后用贪心算法求剩余的数
        int f1 = 1, f2 = 1;
        int fn = f1 + f2;
        while (fn <= k) {
            f1 = f2;
            f2 = fn;
            fn  = f1 + f2;
        }
        //结束后 fn >= k, f2是最逼近k的斐波那契数
        
        int result = 0;
        
        while (k) {
            if (k >= f2) {
                k -= f2;
                result++;
            } else {
                int prev = f2 - f1; //求前一个斐波那契数
                f2 = f1;
                f1 = prev;
            }
        }
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();