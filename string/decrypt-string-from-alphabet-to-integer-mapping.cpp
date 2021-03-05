//1309. Decrypt String from Alphabet to Integer Mapping
class Solution {
public:
    string freqAlphabets(string s) {
        string result;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '#') {
                char c = (s[i - 2] - '0') * 10 + s[i - 1] + '0';
                result.insert(result.begin(), c);
                i -= 2;
            } else {
                char c = s[i] + '0';
                result.insert(result.begin(), c);
            }
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