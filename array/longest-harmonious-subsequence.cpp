//594. Longest Harmonious Subsequence
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> cnts;
        for (int num : nums) {
            cnts[num]++;
        }
        
        int result = 0;
        for (const auto& p : cnts) {
            if (cnts.count(p.first + 1))
                result = max(result, p.second + cnts[p.first + 1]);
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