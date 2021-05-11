//997. Find the Town Judge
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (1 == N && trust.empty())
            return 1;
        
        vector<int> incomes(N + 1), outcomes(N + 1);
        for (auto t : trust) {
            outcomes[t[0]]++;
            incomes[t[1]]++;
        }
        
        int result = -1, count = 0;
        
        for (int i = 0; i <= N; ++i) {
            if (incomes[i] == N - 1 && outcomes[i] == 0) {
                result = i;
                count++;
            }
        }
        
        return count == 1 ? result : -1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();