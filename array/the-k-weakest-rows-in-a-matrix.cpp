//1337. The K Weakest Rows in a Matrix
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        
        vector<pair<int, int>> cntPairs;
        
        int rows = mat.size(), cols = mat[0].size();
        
        for (int i = 0; i< rows; ++i) {
            int count = 0;
            for (int j= 0; j < cols; ++j) {
                if (mat[i][j] == 1)
                    ++count;                        
            }
            cntPairs.push_back({count, i});
        }
        
        sort(cntPairs.begin(), cntPairs.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            if (lhs.first == rhs.first)
                return lhs.second < rhs.second;
            return lhs.first < rhs.first;
        });
        
        for (int i = 0; i < k; ++i) {
            result.push_back(cntPairs[i].second);
        }
        
        return result;
    }
};

static auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();