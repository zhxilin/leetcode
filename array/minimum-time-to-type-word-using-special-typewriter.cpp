//1974. Minimum Time to Type Word Using Special Typewriter
class Solution {
public:
    int minTimeToType(string word) {
        int n = word.size();

        char cur = 'a';

        int result = n;

        for (int i = 0; i < n; ++i) {
            int dist1 = abs(word[i] - cur);
            int dist2 = abs(26 - dist1);
            result += min(dist1, dist2);
            cur = word[i];
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