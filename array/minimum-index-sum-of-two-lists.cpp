//599. Minimum Index Sum of Two Lists
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n1 = list1.size(), n2 = list2.size();
        unordered_map<int, vector<string>> mx;
        
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (list1[i] != list2[j])
                    continue;
                
                mx[i + j].push_back(list1[i]);
            }
        }
        
        int minIndexSum = INT_MAX;
        for (auto p : mx) {
            minIndexSum = min(minIndexSum, p.first);
        }
        
        return mx[minIndexSum];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();