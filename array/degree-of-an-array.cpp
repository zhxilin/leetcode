//697. Degree of an Array
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left, right, counts;
        
        int degree = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            //记录同一个数值出现的最左和最右位置
            if (!left.count(num))
                left[num] = i;
            
            right[num] = i;
            
            counts[num]++;
            
            degree = max(degree, counts[num]);
        }
        
        int result = INT_MAX;
        
        for (auto itr = counts.begin(); itr != counts.end(); ++itr) {
            if (itr->second == degree)
                result = min(result, right[itr->first] - left[itr->first] + 1);
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