//39. Combination Sum
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        
        vector<int> cur;
        backtracking(candidates, target, result, 0, cur);
        
        return result;
    }

private:
    void backtracking(vector<int>& candidates, int target, vector<vector<int>>& result, int index, vector<int>& cur) {
        if (0 == target) {
            result.push_back(cur);
            return;
        }
        
        if (target < 0)
            return;
        
        for (int i = index; i < candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], result, i, cur);
            cur.pop_back();
        }
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();