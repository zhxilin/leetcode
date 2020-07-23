//1409. Queries on a Permutation With Key
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> pIndex(m);
        for (int i = 0; i < m; ++i) {
            pIndex[i] = i;
        }
        
        vector<int> result;
        
        for (int query : queries) {
            int index = pIndex[query - 1];
            
            result.push_back(index);
            
            //小于查询下标的索引都加1,表示右移1位
            for (int i = 0; i < m; ++i) {
                if (pIndex[i] < index)
                    pIndex[i]++;
            }
            pIndex[query - 1] = 0;
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