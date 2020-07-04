//118. Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;        
        for (int i = 0; i < numRows; ++i) {
            vector<int> v(i + 1, 1);            
            for (int j = 0; j <= i; ++j) {
                if (0 == j || j == i)
                    continue;
                v[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            
            result.push_back(std::move(v));
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