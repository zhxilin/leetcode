//605. Can Place Flowers
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        
        for (int i=0; i < size; ++i) {
            if (flowerbed[i] == 0) {
                if (i - 1 >= 0 && flowerbed[i - 1] == 1)
                    continue;
                
                if (i + 1 < size && flowerbed[i + 1] == 1)
                    continue;
                
                count++;
                flowerbed[i] = 1;
            }
            
            if (count >= n)
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