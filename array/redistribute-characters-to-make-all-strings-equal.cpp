//1897. Redistribute Characters to Make All Strings Equal
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> mx(26);
        
        int n = words.size();
        
        for (auto word : words) {
            for (auto c : word) {
                mx[c - 'a']++;
            }
        }
        
        for (int cnt : mx) {
            if (cnt % n != 0)
                return false;
        }
        
        return true;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();