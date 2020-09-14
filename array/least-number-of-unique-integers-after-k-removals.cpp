//1481. Least Number of Unique Integers after K Removals
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mx;
        for (int num : arr) {
            mx[num]++;
        }
        
        vector<int> mv;
        for (auto& itr : mx) {
            mv.push_back(itr.second);
        }
        
        sort(mv.begin(), mv.end());
        
        for (int i = 0; i < mv.size(); ++i) {
            k -= mv[i];
            if (k < 0)
                return mv.size() - i;
        }
        
        return 0;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();