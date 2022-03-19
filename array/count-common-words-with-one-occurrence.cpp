//2085. Count Common Words With One Occurrence
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, pair<int, int>> mx;

        for (auto& word : words1) {
            mx[word].first++;
        }

        for (auto& word : words2) {
            mx[word].second++;
        }

        int result = 0;
        for (auto& p : mx) {
            if (p.second.first == 1 && p.second.second == 1)
                result++;
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