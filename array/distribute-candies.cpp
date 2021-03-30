//575. Distribute Candies
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> mx;
        for (int type : candyType) {
            mx[type]++;
        }
        
        int result = min(candyType.size() / 2, mx.size());
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;  
};