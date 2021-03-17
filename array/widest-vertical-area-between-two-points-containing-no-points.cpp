//1637. Widest Vertical Area Between Two Points Containing No Points
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> v;
        for (int i = 0; i < points.size(); ++i) {
            v.push_back(points[i][0]);
        }
        sort(v.begin(), v.end());
        
        int result = 0;
        for (int i = 0; i < v.size() - 1; ++i) {
            result = max(result, v[i + 1] - v[i]);
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