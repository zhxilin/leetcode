//830. Positions of Large Groups
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        
        int size = S.size();
        int i = 0, start = 0;
        
        while (i++ < size) {
            if (S[i] != S[start]) {
                if (i - start >= 3)
                    result.push_back({start, i - 1});
                
                start = i;
            }
        }

        if (i - start >= 3)
            result.push_back({start, i - 1 });

        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();