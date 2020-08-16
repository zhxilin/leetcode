//1550. Three Consecutive Odds
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds = 0;
        
        for (int i = 0; i < arr.size() && odds < 3; ++i) {
            odds = arr[i] % 2 ? odds + 1 : 0;
            if (3 == odds) 
                return true;
        }
        
        return false;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();