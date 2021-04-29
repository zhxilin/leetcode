//1071. Greatest Common Divisor of Strings
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1)
            return "";
        
        int gcd = std::gcd(str1.size(), str2.size());
        return str1.substr(0, gcd);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();