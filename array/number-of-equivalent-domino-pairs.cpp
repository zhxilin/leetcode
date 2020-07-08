//1128. Number of Equivalent Domino Pairs
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int result = 0;
        vector<int> cnts(100, 0);
        
        for (auto domino : dominoes) {
            int minVal = min(domino[0], domino[1]);
            int maxVal = max(domino[0], domino[1]);
            
            int val = 10 * maxVal + minVal;
            
            result += cnts[val]++;
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