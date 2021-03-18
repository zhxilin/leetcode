//797. All Paths From Source to Target
class Solution {
public:
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(graph, 0, path, result);
        
        return result;
    }
       
private:
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& result) {
        path.push_back(node);
        if (node == graph.size() - 1)
            result.push_back(path);
        else {
            for (auto& dest : graph[node]) {
                dfs(graph, dest, path, result);
            }
        }
        path.pop_back();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();