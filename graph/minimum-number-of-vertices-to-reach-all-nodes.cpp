//1557. Minimum Number of Vertices to Reach All Nodes
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> incomes;
        for (auto& edge : edges) {
            incomes.insert(edge[1]);
        }
        
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!incomes.count(i))
                result.push_back(i);
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