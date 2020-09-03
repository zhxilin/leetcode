//319. Bulb Switcher
class Solution {
public:
    int bulbSwitch(int n) {
        //对于第i个灯泡，当i % d == 0时，灯泡需要翻转一次，
        //问题最后求点亮的灯数，等价于求令i可以整除的除数（整除因子）的数量为奇数的情况
        //而只有完全平方数拥有奇数个整除因子，例如
        //1: 1
        //4: 1, 2, 4
        //9: 1, 3, 9
        //16:1,2,4,8,16
        //...
        return floor(sqrt(n));
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();