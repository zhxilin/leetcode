//1295. Find Numbers with Even Number of Digits
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            int cnt = 1;
            while (num/10) {
                cnt++;
                num /= 10;
            }
            result += 0 == cnt % 2;
        }
        
        return result;
    }
};