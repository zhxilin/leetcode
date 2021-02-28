//1662. Check If Two String Arrays are Equivalent
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        stringstream ss1, ss2;
        
        for (auto s : word1) {
            ss1 << s;
        }
        
        for (auto s : word2) {
            ss2 << s;
        }
        
        return ss1.str() == ss2.str();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();