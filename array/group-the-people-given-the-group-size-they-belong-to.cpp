//1282. Group the People Given the Group Size They Belong To
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> cnts;
        //先按组号分组　
        for (int i = 0; i < groupSizes.size(); ++i) {
            cnts[groupSizes[i]].push_back(i);
        }
        
        //再贪心算法每组细分
        vector<vector<int>> result;
        
        for (const auto& cnt : cnts) {
            int groupSize = cnt.first;
            vector<int> candidates = cnt.second;
            
            vector<int> tmp;
            for (int i = 0; i < candidates.size(); ++i) {
                tmp.push_back(candidates[i]);
                if ((i + 1) % groupSize == 0) {
                    result.push_back(tmp);
                    tmp.clear();
                }
            }
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