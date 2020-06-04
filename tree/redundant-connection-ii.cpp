//685. Redundant Connection II
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        //思路：用并查集（UnionFind)将所有节点进行union，在union过程中两个节点均有父节点，则为多余边
        vector<int> disjointSet(edges.size() + 1, -1);
       
        //本题比#684复杂的点在于图是有可能存在环的，换言之，同一个节点可能存在多个父节点，
        //而目标结果要求构成一个树结构，树的特点是每个节点最多只有一个父节点！
        //所以需要找到第一次出现2个父节点的位置
        int pos = 0;
        for (const vector<int>& edge: edges) {
            if (disjointSet[edge[1]] != -1)
                break;
            disjointSet[edge[1]] = pos++;
        }
        
        //将含有两个父节点的边都移动到最后
        if (pos < edges.size()) {
            vector<int> edge1 = edges[pos];
            vector<int> edge2 = edges[disjointSet[edge1[1]]];
            edges.erase(edges.begin() + pos);
            edges.erase(edges.begin() + disjointSet[edge2[1]]);
            edges.push_back(edge2);
            edges.push_back(edge1);
        }
       
        //重置disjointSet
        for (int i = 0; i < disjointSet.size(); ++i)
            disjointSet[i] = -1;
       
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