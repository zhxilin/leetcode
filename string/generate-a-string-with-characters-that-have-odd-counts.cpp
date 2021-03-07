//1374. Generate a String With Characters That Have Odd Counts
class Solution {
public:
    string generateTheString(int n) {
        if (n % 2 != 0) 
            return string(n, 'a');
        
        return string(n - 1, 'a') + "b";
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();