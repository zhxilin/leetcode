//419. Battleships in a Board
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('X' == board[i][j] && 
                   (i == 0 || 'X' != board[i - 1][j]) &&
                   (j == 0 || 'X' != board[i][j - 1]))
                    result++;
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