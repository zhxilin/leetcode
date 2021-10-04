//168. Excel Sheet Column Title
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        
        while (columnNumber) {
            columnNumber--;
            int k = columnNumber % 26;
            
            result += 'A' + k;
            
            columnNumber /= 26;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();