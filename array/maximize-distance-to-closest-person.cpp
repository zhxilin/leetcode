//849. Maximize Distance to Closest Person
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxDistance = 0, j = -1;
        
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i]) {
                maxDistance = j < 0 ? 
                    max(maxDistance, i) : //从头开始都是0遇到1停下
                    max(maxDistance, (i - j) / 2); //在两个1之间停下
                
                j = i;
            } else if (i == seats.size() - 1)
                maxDistance = max(maxDistance, i - j); //计算连续0的长度
        }
        
        return maxDistance;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();