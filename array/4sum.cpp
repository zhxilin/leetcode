//18. 4Sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(); 
        vector<vector<int>> result;
        
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            if (i > 0 && a == nums[i - 1]) 
                continue;
            
            for (int j = i + 1; j < n; ++j) {
                int b = nums[j];
                if (j > i + 1 && b == nums[j - 1])
                    continue;
            
                int low = j + 1, high = n - 1;

                while (low < high) {
                    int c = nums[low], d = nums[high];
                    int sum = a + b + c + d;
                    if (sum < target)
                        low++;
                    else if (sum > target)
                        high--;
                    else {
                        result.push_back({a, b, c, d});
                        low++;
                        high--;
                        while (low < high && nums[low] == nums[low - 1]) low++;
                        while (low < high && nums[high] == nums[high + 1]) high--;
                    }
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