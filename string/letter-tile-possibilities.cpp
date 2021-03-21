//1079. Letter Tile Possibilities
class Solution {
public:
    int numTilePossibilities(string tiles) {
        
        sort(tiles.begin(), tiles.end());        
        vector<bool> visited(tiles.size());
        
        int result = 0;
        dfs(tiles, visited, result);
        
        return result;
    }
    
private:
    
    void dfs(string tiles, vector<bool>& visited, int& result) {
        for (int i = 0; i < tiles.size(); ++i) {
            if (visited[i])
                continue;
            
            if (i > 0 && tiles[i - 1] == tiles[i] && !visited[i - 1])
                continue;
            
            visited[i] = true;
            result++;
            
            dfs(tiles, visited, result);
            
            visited[i] = false;
        }
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
