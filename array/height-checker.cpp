//1051. Height Checker
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp(heights);
        
        int result = 0;
        sort(tmp.begin(), tmp.end());
        
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] != heights[i])
                result++;
        }
        return result;
    }
};