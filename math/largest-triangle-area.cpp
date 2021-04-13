//812. Largest Triangle Area
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        //O为三角形重心,O(xa,yc)
        //Sabc = Saob + Sboc + Scoa
        //     = 1/2*(xa-xb)*(ya-yc) + 1/2*(xc-xa)*(ya-yc) + 1/2*(xc-xa)(yc-yb)
        //     = 1/2*(xayb + xbyc + xcyb - xayc - xcyb - xbya)
        int n = points.size();
        double result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    result = max(result, area(points[i], points[j], points[k]));
                }
            }
        }
        
        return result;
    }
    
private:
    double area(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
        return 0.5 * abs(a[0]*b[1] + b[0]*c[1] + c[0]*a[1] - a[0]*c[1] - c[0]*b[1] - b[0]*a[1]);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();