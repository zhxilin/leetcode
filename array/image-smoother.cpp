//661. Image Smoother
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        
        vector<vector<int>> result(m, vector<int>(n));
        
        //一个点的周围8个方向
        vector<pair<int, int>> directions = { 
            {-1, -1 }, {-1, 0 }, {-1, 1 },
            { 0, -1 }, { 0, 0 }, { 0, 1 },
            { 1, -1 }, { 1, 0 }, { 1, 1 } };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                
                for (auto dir : directions) {
                    int di = i + dir.first;
                    int dj = j + dir.second;
                    if (di >= 0 && dj >= 0 && di < m && dj < n) {
                        result[i][j] += M[di][dj];
                        cnt++;
                    }    
                }
                
                result[i][j] /= cnt;
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