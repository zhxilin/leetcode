//1817. Finding the Users Active Minutes
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> result(k);
        unordered_map<int, set<int>> mx;
        
        for (auto log : logs) {
            mx[log[0]].insert(log[1]);
        }
        
        for (auto p : mx) {
            result[p.second.size() - 1]++;
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