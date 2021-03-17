//1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
class Solution {
public:
    int minPartitions(string n) {
        int result = 0;
        for (int i = 0; i < n.size(); ++i) {
            result = max(result, n[i] - '0');
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