//1431. Kids With the Greatest Number of Candies
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = INT_MIN;
        for (int candy : candies) {
            if (candy > max)
                max = candy;
        }
        
        vector<bool> result;
        
        for (int i = 0; i < candies.size(); ++i) {
            result.push_back(candies[i] + extraCandies >= max);
        }
        
        return result;
    }
};