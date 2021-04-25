//387. First Unique Character in a String
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(26);
        for (auto c : s) {
            vec[c - 'a']++;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (vec[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();