//1464. Maximum Product of Two Elements in an Array
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        sort(nums.begin(), nums.end(), greater<int>());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};