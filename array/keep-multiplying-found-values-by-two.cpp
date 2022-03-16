//2154. Keep Multiplying Found Values by Two
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> s;
        
        for (int n : nums) {
            s.insert(n);
        }
        
        while (s.count(original)) {
            original *= 2;
        }
        
        return original;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();