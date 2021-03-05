//1725. Number Of Rectangles That Can Form The Largest Square
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        unordered_map<int, int> cnts;
        for (auto& rect : rectangles) {
            int side = min(rect[0], rect[1]);
            cnts[side]++;
            maxLen = max(maxLen, side);
        }
        
        return cnts[maxLen];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();