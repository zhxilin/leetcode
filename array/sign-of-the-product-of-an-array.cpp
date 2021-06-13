//1822. Sign of the Product of an Array
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for (int num : nums) {
            if (num == 0)
                return 0;
            if (num < 0)
                neg++;
        }
        
        return neg % 2 == 1 ? -1 : 1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();