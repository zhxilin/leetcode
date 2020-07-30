//1222. Queens That Can Attack the King
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {     
        vector<vector<int>> result;
        vector<vector<int>> board(8, vector<int>(8));
        vector<vector<int>> dirs({
            { 0,  1 },
            { 0, -1 },
            { 1,  0 },
            {-1,  0 },
            { 1, 1 },
            {-1,  1 },
            { 1, -1 },
            {-1, -1 }
        });
        
        for (auto queen : queens) {
            board[queen[0]][queen[1]] = 1;
        }
        
        int kingX = king[0], kingY = king[1];
        
        for (auto dir : dirs) {
            
            for (int x = kingX + dir[0], y = kingY + dir[1]; x >= 0 && x < 8 && y >= 0 && y < 8; x += dir[0], y += dir[1]) {
                if (board[x][y]) {
                    result.push_back({x, y});
                    break;
                }
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