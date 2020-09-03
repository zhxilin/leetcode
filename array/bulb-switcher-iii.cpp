//1375. Bulb Switcher III
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        //当点亮的灯泡数和当前点亮的最大灯号一致时，计数+1
        int count = 0, maxi = 0;
        for (int i = 0; i < light.size(); ++i) {
            maxi = max(maxi, light[i]);
            if (maxi == i + 1)
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