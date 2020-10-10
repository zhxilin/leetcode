//1608. Special Array With X Elements Greater Than or Equal X
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int result = -1;
        
        int n = nums.size();
        
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                cnt += nums[j] >= i;
            }
            if (cnt == i) {
                result = cnt;
                break;
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