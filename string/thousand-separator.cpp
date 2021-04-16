//1556. Thousand Separator
class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) 
            return "0";
        
        int count = 0; 
        string s;
        
        while (n) {
            s = to_string(n % 10) + s; 
            n /= 10; 
            
            if (++count == 3) {
                if (n > 0) 
                    s = "." + s; 
                count = 0;
            }
        }
        
        return s;
    }
};
static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();