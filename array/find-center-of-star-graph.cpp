//1791. Find Center of Star Graph
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> cnts;
        
        int result = 0;
        for (auto& edge : edges) {
            int n1 = edge[0], n2 = edge[1];
            cnts[n1]++;
            cnts[n2]++;
            if (cnts[n1] > 1) {
                result = n1;
                break;
            }
            if (cnts[n2] > 1) {
                result = n2;
                break;
            }
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