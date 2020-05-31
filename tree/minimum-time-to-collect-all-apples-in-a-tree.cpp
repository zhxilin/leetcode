//1443. Minimum Time to Collect All Apples in a Tree
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //构建邻接图
        vector<vector<int>> graph(n);        
        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        unordered_set<int> visited;
        return dfs(graph, hasApple, 0, 0, visited);
    }
    
    int dfs(const vector<vector<int>>& graph, vector<bool>& hasApple, int src, int cost, unordered_set<int>& visited) {
        if (visited.count(src)) return 0;
        visited.insert(src);
        
        int subCost = 0;
        //从src节点出发的目标节点的花费之和为当前节点的子花费
        //由于一个节点搜索后需要返回父节点，故消耗固定为2
        for (int node : graph[src]) {
            subCost += dfs(graph, hasApple, node, 2, visited);
        }
        
        if (0 == subCost && !hasApple[src])
            return 0;
        
        return cost + subCost;
    }
};