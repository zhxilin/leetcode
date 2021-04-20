//733. Flood Fill
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        int pixel = image[sr][sc];
        dfs(image, sr, sc, pixel, newColor, visited);
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int pixel, int newColor, vector<vector<bool>>& visited) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
            return;

        if (visited[sr][sc])
            return;

        visited[sr][sc] = true;

        if (image[sr][sc] != pixel)
            return;

        image[sr][sc] = newColor;
        
        for (auto dir : dirs) {
            dfs(image, sr + dir[0], sc + dir[1], pixel, newColor, visited);
        }
    }
    
private:
    int dirs[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();