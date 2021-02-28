//1773. Count Items Matching a Rule
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int result = 0;
        
        for (const vector<string>& item : items) {
            if (ruleKey == "type") {
                result += item[0] == ruleValue;
            } else if (ruleKey == "color") {
                result += item[1] == ruleValue;                
            } else if (ruleKey == "name") {
                result += item[2] == ruleValue;                
            }
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