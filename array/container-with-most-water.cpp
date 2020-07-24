//11. Container With Most Water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int l = 0, r = height.size() - 1;
        
        while (l < r) {
            //面积取决于两条线中较短的线
            result = max(result, min(height[l], height[r]) * (r - l));
            
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        
        return result;
    }
};

static auto _ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();