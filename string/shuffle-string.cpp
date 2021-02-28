//1528. Shuffle String
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result(s);
        
        for (int i = 0; i < indices.size(); ++i) {
            result[indices[i]] = s[i];
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