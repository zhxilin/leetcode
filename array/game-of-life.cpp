//289. Game of Life
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        //Rule1: live->dead  -1
        //Rule2: live->live   1 
        //       dead->dead   0
        //Rule3: live->dead  -1
        //Rule4: dead->live.  2
        //最终>0 -> live, <=0 -> dead
        
        vector<pair<int,int>> neighbors{
            {-1, -1 }, {-1, 0 }, {-1, 1 },
            { 0, -1 },           { 0, 1 },
            { 1, -1 }, { 1, 0 }, { 1, 1 }
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                int liveNeighbors = 0;
                
                //统计活邻居
                for (auto neighbor : neighbors) {                    
                    int r = i + neighbor.first, c = j + neighbor.second;
                    if ((r < m && r >= 0) && (c < n && c >= 0) && abs(board[r][c]) == 1)
                        liveNeighbors++;
                }
                
                //Rule1或Rule3
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3))
                    board[i][j] = -1;
                
                //Rule4
                if (board[i][j] == 0 && liveNeighbors == 3)
                    board[i][j] = 2;
                
                //Rule2不变
            }
        }
        
        //刷新最终状态
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = board[i][j] > 0;
            }
        }
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();