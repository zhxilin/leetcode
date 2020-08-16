//228. Summary Ranges
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        int index = 0, n = nums.size();
        stringstream ss;
        
        while (index < n) {
            int cur = index;
            
            ss.str("");            
            ss << nums[index];
            
            bool ranged = false;
            while (cur < n - 1 && nums[cur + 1] == nums[cur] + 1) {
                cur++;
                ranged = true;
            }
            
            if (ranged)
                ss << "->" << nums[cur];
            
            result.push_back(ss.str());
            
            index = cur + 1;
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