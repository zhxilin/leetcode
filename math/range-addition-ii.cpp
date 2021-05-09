//598. Range Addition II
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        
        return m * n;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();