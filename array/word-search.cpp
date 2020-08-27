//79. Word Search
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (word[0] != board[i][j])
                    continue;
                
                if (dfs(board, i, j, word, 0))
                    return true;
            }
        }
        
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int index) {
        if (index >= word.size()) 
            return true;
        
        int m = board.size(), n = board[0].size();
        
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        
        if (word[index] != board[i][j]) 
            return false;
        
        char temp = board[i][j];
        board[i][j] = '*'; //表示已访问，避免使用额外的已访问列表
        
        if (dfs(board, i + 1, j, word, index + 1) ||
            dfs(board, i - 1, j, word, index + 1) ||
            dfs(board, i, j + 1, word, index + 1) ||
            dfs(board, i, j - 1, word, index + 1))
            return true;
        
        board[i][j] = temp; //回溯后赋回原值
        
        return false;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();