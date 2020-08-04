//746. Min Cost Climbing Stairs
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
         int f1 = 0, f2 = 0;
        for (int i = cost.size() - 1; i >= 0; --i) {
            int f0 = cost[i] + min(f1, f2);
            f2 = f1;
            f1 = f0;
        }
        
        return min(f1, f2);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();