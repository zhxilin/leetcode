//1466. Reorder Routes to Make All Paths Lead to the City Zero
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        //1.构建连接图
        vector<vector<int>> graph(n);
        buildGraph(connections, graph);
        
        //2.从每个节点BFS其出度节点，若出度节点不在已访问集合，则表示该出度节点的边需要逆转
        int result = 0;
        queue<int> q;
        unordered_set<int> visited;
        
        for (int i = 0; i < n; ++i) {
            if (visited.count(i)) continue;
            
            q.push(i);
            visited.insert(i);
            
            while (!q.empty()) {
                int size = q.size();
                
                while (size--) {
                    int u = q.front();
                    q.pop();
                    
                    for (int v : graph[u]) {
                        if (visited.count(v)) continue;
                        q.push(v);
                        visited.insert(v);
                        result++;
                    }
                }
            }
        }
        
        return result;
    }
    
    void buildGraph(const vector<vector<int>>& connections, vector<vector<int>>& graph) {
        for (int i = 0; i < connections.size(); ++i) {
            graph[connections[i][0]].push_back(connections[i][1]);
        }
    }
};