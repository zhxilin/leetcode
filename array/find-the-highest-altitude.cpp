//1732. Find the Highest Altitude
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0, altitude = 0;
        
        for (int g : gain) {
            altitude += g;
            result = max(result, altitude);
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