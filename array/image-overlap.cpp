//835. Image Overlap
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        //将2维坐标转成1维坐标(i, j) -> i * 100 + j
        vector<int> vA, vB;
        
        int m = A.size(), n = A[0].size();
        
        unordered_map<int, int> counts;
        
        auto hasher = [](int i, int j)->int { return i * 100 + j; };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 1)
                    vA.push_back(hasher(i, j));
                if (B[i][j] == 1)
                    vB.push_back(hasher(i, j));
            }
        }
        
        for (int a : vA) {
            for (int b : vB) {
                counts[a - b]++;
            }
        }
        
        int result = 0;
        for (auto itr : counts) {
            result = max(result, itr.second);
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