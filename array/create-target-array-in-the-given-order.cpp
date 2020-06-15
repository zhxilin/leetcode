//1389. Create Target Array in the Given Order
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result;
        for (int i = 0; i < index.size(); ++i) {
            int pos = index[i];
            int num = nums[i];
            result.insert(result.begin() + pos, num);
        }
        
        return result;
    }
};