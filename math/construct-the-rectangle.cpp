//492. Construct the Rectangle
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int x = sqrt(area);
        while (1) {
          if (area % x == 0) 
              break;
          x--;
        }
        
        return { area / x , x };
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();