//1779. Find Nearest Point That Has the Same X or Y Coordinate
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        
        int dist = INT_MAX;
        int result = -1;
        for (int i = n - 1; i >= 0; --i) {
            int px = points[i][0], py = points[i][1];
            if (px != x && py != y)
                continue;
            
            int md = abs(px - x) + abs(py - y);
            if (md <= dist) {
                dist = md;
                result = i;
            }
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