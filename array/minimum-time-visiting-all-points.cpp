//1266. Minimum Time Visiting All Points
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result = 0;
        
        vector<int> p1 = points[0];
        for (int i = 1; i < points.size(); ++i) {
            const vector<int>& p2 = points[i];
            int dx = p1[0] - p2[0];
            int dy = p1[1] - p2[1];
            result += max(abs(dx), abs(dy));
            p1 = p2;
        }
        
        return result;
    }
};