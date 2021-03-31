//1189. Maximum Number of Balloons
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> vec(26);
        for (auto c : text) {
            vec[c - 'a']++;
        }
        
        return min({vec['b' - 'a'], vec['a' - 'a'], vec['l' - 'a'] / 2, vec['o' - 'a'] / 2, vec['n' - 'a']});
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();