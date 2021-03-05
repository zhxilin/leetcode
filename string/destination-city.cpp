//1436. Destination City
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mx;
        for (auto& path : paths) {
            mx[path[0]] = path[1];
        }
        
        string dest = paths[0][0];
        while (mx.count(dest)) {
            dest = mx[dest];
        }
        
        return dest;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();