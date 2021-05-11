//1828. Queries on Number of Points Inside a Circle
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> result;
        for (auto q : queries) {
            int cx = q[0], cy = q[1], cr = q[2];
            int pr = cr * cr;
            int count = 0;
            for (auto p : points) {
                int px = p[0], py = p[1];
                if (pow(px - cx, 2) + pow(py - cy, 2) <= pr)
                    count++;
            }
            result.push_back(count);
        }
        return result;
    }
};