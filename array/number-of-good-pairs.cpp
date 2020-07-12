//1512. Number of Good Pairs
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        //C(n,2)=n*(n-1)/2
        int count[101] = {};
        for (int n: nums)
            count[n]++;
        
        int result = accumulate(begin(count), end(count), 0, [](int lhs, int rhs) {
            return lhs + rhs * (rhs - 1) / 2;
        });
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();