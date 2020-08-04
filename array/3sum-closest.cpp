//16. 3Sum Closest
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();        
        int closestSum = nums[n - 3] + nums[n - 2] + nums[n - 1];
        
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            
            int low = i + 1, high = n - 1;
            
            while (low < high) {
                int b = nums[low], c = nums[high];
                int sum = a + b + c;
                    
                if (abs(target - sum) < abs(target - closestSum))
                    closestSum = sum;
                else if (sum < target)
                    low++;
                else
                    high--;
            }
        }
        
        return closestSum;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();