//1296. Divide Array in Sets of K Consecutive Numbers
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0)
            return false;
        
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> mx;
        for (int num : nums) {
            mx[num]++;
        }
        
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            
            if (mx[val] == 0)
                continue;
                
            mx[val]--;
                
            for (int j = 1; j < k; ++j) {
                val++;
                if (mx[val] == 0) 
                    return false;
                
                mx[val]--;
            }
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