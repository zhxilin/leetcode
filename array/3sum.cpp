//15. 3Sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {    
        sort(nums.begin(), nums.end());
        
        int n = nums.size(); 
        vector<vector<int>> result;
        
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            if (i > 0 && a == nums[i - 1]) 
                continue;
            
            int low = i + 1, high = n - 1;
            
            while (low < high) {
                int b = nums[low], c = nums[high];
                int sum = a + b + c;
                if (sum < 0)
                    low++;
                else if (sum > 0)
                    high--;
                else {
                    result.push_back({a, b, c});
                    low++;
                    high--;
                    while (low < high && nums[low] == nums[low - 1]) low++;
                    while (low < high && nums[high] == nums[high + 1]) high--;
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