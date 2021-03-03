//1688. Count of Matches in Tournament
class Solution {
public:
    int numberOfMatches(int n) {
        int result = 0;
        while (n >= 2) {
            int match = n / 2;
            n = n % 2 == 0 ? match : match + 1;            
            result += match;
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