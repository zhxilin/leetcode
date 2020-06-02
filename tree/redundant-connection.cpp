//684. Redundant Connection
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //思路：用并查集（UnionFind)将所有节点进行union，在union过程中两个节点均有父节点，则为多余边
        vector<int> disjointSet(edges.size() + 1, -1);
        
        for (const vector<int>& edge: edges) {
            int r1 = dsfind(disjointSet, edge[0]);
            int r2 = dsfind(disjointSet, edge[1]);
            if (r1 == r2) {
                return edge;
            }
            dsunion(disjointSet, edge[0], edge[1]);
        }
        return {};
    }
    
private:
    int dsfind(const vector<int>& disjointSet, int x) {
        //找到一个节点的最顶端父节点
        if (disjointSet[x] == -1) return x;
        return dsfind(disjointSet, disjointSet[x]);
    }
    
    void dsunion(vector<int>& disjointSet, int x, int y) {
        //若两节点最顶父节点不同，则将其中一个顶端父节点指向另一个，将两部分连接起来
        int r1 = dsfind(disjointSet, x);
        int r2 = dsfind(disjointSet, y);
        if (r1 != r2)
            disjointSet[r1] = r2;
    }
};