//1493. Longest Subarray of 1's After Deleting One Element
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cur = 0, last = 0, result = 0, size = nums.size();
        
        for (int num : nums) {
            if (num) 
                cur++;
            else {
                result = max(result, cur + last);
                last = cur;
                cur = 0;
            }
        }
        
        result = max(result, cur + last);
        return min(result, size - 1);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();