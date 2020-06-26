//1413. Minimum Value to Get Positive Step by Step Sum
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mins = 0, sum = 0;
        
        for (int num : nums) {
            sum += num;
            mins = min(mins, sum);
        }
        
        return 1 - mins;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();