//2185. Counting Words With a Given Prefix
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0;
        int size = pref.size();

        for (auto& word : words) {
            if (word.substr(0, size) == pref)
                result++;
        }

        return result;
    }
};

static auto _ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();