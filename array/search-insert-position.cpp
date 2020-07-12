//35. Search Insert Position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) {
                result = i;
                break;
            }
        }
        return result;
    }
};