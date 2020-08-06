//54. Spiral Matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
            
        vector<int> result;
        
        int m = matrix.size(), n = matrix[0].size();
        
        int r1 = 0, r2 = m - 1;
        int c1 = 0, c2 = n - 1;
        
        //按一圈一圈的方式往里缩进，每一圈按照上、右、下、左，4条边的顺序遍历
        //上：c1,...c2, 此时行为r1
        //右：r1+1,...,r2，此时列为c2
        //下：c2-1,...c1，此时行为r2
        //左：r2-1,...r1+1，此时列为c1
        while (r1 <= r2 && c1 <= c2) {
            
            for (int c = c1; c <= c2; ++c)
                result.push_back(matrix[r1][c]);
            r1++;
            
            for (int r = r1; r <= r2; ++r)
                result.push_back(matrix[r][c2]);
            c2--;
            
            //注意仅剩一行和一列的情况
            if (r1 <= r2) {
                for (int c = c2; c >= c1; --c)
                    result.push_back(matrix[r2][c]);
                r2--;
            }
              
            if (c1 <= c2) {
                for (int r = r2; r >= r1; --r)
                    result.push_back(matrix[r][c1]);
                c1++;
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