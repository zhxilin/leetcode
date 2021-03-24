//1030. Matrix Cells in Distance Order
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<cell> cells;
        
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cell cl;
                cl.dist = abs(i - r0) + abs(j - c0);
                cl.r = i;
                cl.c = j;
                cells.push_back(cl);
            }
        }
        
        sort(cells.begin(), cells.end(), [](const cell& lhs, const cell& rhs) {
            return lhs.dist < rhs.dist;
        });
        
        vector<vector<int>> result;
        for (const cell& cl : cells) {
            result.push_back(vector<int>{cl.r, cl.c});
        }
        return result;
    }

private:
    struct cell {
        int dist;
        int r;
        int c;
    };
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();