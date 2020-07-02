//485. Max Consecutive Ones
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCons = 0, tmp = 0;
        for (int num : nums) {
            if (1 == num) 
                tmp++;
            else
                tmp = 0;
            maxCons = max(maxCons, tmp);
        }
        
        return maxCons;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();