//999. Available Captures for Rook
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        //找到R的位置
        int rX = 0, rY = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'R') {
                    rX = i, rY = j;
                    break;
                }
            }
        }
        
        int result = 0;
        //R的北方向
        for (int i = rX - 1; i >= 0; --i) {
            if (board[i][rY] == 'B')
                break;
            
            if (board[i][rY] == 'p') {
                result++;
                break;
            }
        }
        
        //R的南方向
        for (int i = rX + 1; i < m; ++i) {
            if (board[i][rY] == 'B')
                break;
            
            if (board[i][rY] == 'p') {
                result++;
                break;
            }
        }
        
        //R的东方向
        for (int i = rY + 1; i < n; ++i) {
            if (board[rX][i] == 'B')
                break;
            
            if (board[rX][i] == 'p') {
                result++;
                break;
            }
        }
        
        //R的西方向
        for (int i = rY - 1; i >= 0; --i) {
            if (board[rX][i] == 'B')
                break;
            
            if (board[rX][i] == 'p') {
                result++;
                break;
            }
        }
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();