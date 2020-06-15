//1313. Decompress Run-Length Encoded List
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i += 2) {
            int freq = nums[i];
            int val = nums[i + 1];
            
            while (freq--) {
                result.push_back(val);
            }
        }
        
        return result;
    }
};