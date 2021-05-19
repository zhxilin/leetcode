//1806. Minimum Number of Operations to Reinitialize a Permutation
class Solution {
public:
    int reinitializePermutation(int n) {
        //当0之后的索引任意一个与原始位置相同,则其他索引也一定相同
        //
        int prev = 1, count = 1, present = n / 2;
        while (prev != present) {
            if (present % 2 == 0)
                present = present / 2;
            else
                present = n / 2 + (present - 1) / 2;
            
            count++;
        }
        
        return count;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();