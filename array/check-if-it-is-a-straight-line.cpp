//1232. Check If It Is a Straight Line
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int deltaX = coordinates[1][0] - coordinates[0][0];
        int deltaY = coordinates[1][1] - coordinates[0][1];
        
        for (int i = 2; i < coordinates.size(); ++i) {
            int dx = coordinates[i][0] - coordinates[0][0];
            int dy = coordinates[i][1] - coordinates[0][1];
            if (dx * deltaY != dy * deltaX) {
                return false;
            }
        }
        
        return true;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();