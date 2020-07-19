//532. K-diff Pairs in an Array
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        unordered_map<int, int> mx;
        for (int num : nums) {
            mx[num]++;
        }
        
        int result = 0;
        
        for (auto itr = mx.begin(); itr != mx.end(); ++itr) {
            if (k == 0 && itr->second > 1)
                result++;
            
            if (k != 0 && mx.count(itr->first + k))
                result++;
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