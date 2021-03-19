//1561. Maximum Number of Coins You Can Get
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //First of all, sort all piles as a ascending sequence.
        //In this game, Alice will always take the max element, that is, the last one.
        //And you will always take the second last one.
        //Bob will always take the min element, that is, the first one.
        sort(piles.begin(), piles.end());
        
        int result = 0;
        
        int n = piles.size() / 3;
        for (int i = 0; i < n; ++i) {
            //Alice always takes the max element in this turn.
            piles.pop_back(); 
            //You then takes the second max element in this turn.
            result += piles.back(); 
            piles.pop_back();
            
            //Bob always takes the first element element which is the min number.
            //No need to pop the first element because it will not affect your choice.
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