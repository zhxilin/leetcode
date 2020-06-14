//1365. How Many Numbers Are Smaller Than the Current Number
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> mx;
        
        for (int num : nums) {
            mx[num]++;
        }
        
        int prevCnt = 0;
        for (auto itr = mx.begin(); itr != mx.end(); ++itr) {
            int curCnt = itr->second;
            itr->second = prevCnt;
            prevCnt += curCnt;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = mx[nums[i]];
        }
        
        return nums;
    }
};