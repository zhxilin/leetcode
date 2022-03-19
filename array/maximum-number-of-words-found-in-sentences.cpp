//2114. Maximum Number of Words Found in Sentences
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int result = 0;

        for (auto& sentence : sentences) {
            int cnt = 1;

            for (auto c : sentence) {
                if (c == ' ')
                    cnt++;
            }

            result = max(result, cnt);
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