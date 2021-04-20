//1496. Path Crossing
class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> set;
        
        pair<int, int> p(0, 0);
        set.insert(p);
        
        for (auto c : path) {
            if (c == 'N')
                p.second++;
            else if (c == 'S')
                p.second--;
            else if (c == 'E')
                p.first++;
            else
                p.first--;
            
            if (set.count(p))
                return true;
            
            set.insert(p);
        }
        
        return false;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();