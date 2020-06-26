//1217. Play with Chips
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        //题目等价于将数组所有数值变成相同数值的成本最小
        //如果数组元素全部为偶数，全变成2，成本为0。
        //如果数组元素全部为奇数，全变成1，成本为0。
        //如果奇数元素个数大于偶数元素个数，将偶数元素加1全变为奇数，成本是偶数元素的个数。
        //如果奇数元素个数小于偶数元素个数，将奇数元素加1全变为偶数，成本是奇数元素的个数。
        //本题的本质就是求奇数个数和偶数个数两者的最小值
        
        int even = 0, odd = 0;
        for (int chip : chips) {
            if (chip % 2 == 0)
                even++;
            else
                odd++;
        }
        
        return min(even, odd);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();