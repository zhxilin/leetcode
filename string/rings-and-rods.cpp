//2103. Rings and Rods
class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, set<char>> mx;
        for (int i = 0; i < rings.size(); i += 2) {
            int rot = rings[i + 1] - '0';
            char c = rings[i];
            
            mx[rot].insert(c);
        }
        
        int result = 0;
        for (auto& pair : mx) {
            result += pair.second.size() == 3;
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
