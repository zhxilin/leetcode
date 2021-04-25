//1523. Count Odd Numbers in an Interval Range
class Solution {
public:
    int countOdds(int low, int high) {
        int cnt = high - low + 1;
        if (cnt % 2 == 0 || low % 2 == 0)
            return cnt / 2;
        
        return cnt / 2 + 1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();