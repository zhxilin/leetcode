//914. X of a Kind in a Deck of Cards
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mx;
        for(int i : deck) 
            mx[i]++;
        
        int x = 0;
        for(auto i : mx) 
            x = gcd(x, i.second);
        
        return x >= 2;
    }
    
private:
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y % x, x);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();