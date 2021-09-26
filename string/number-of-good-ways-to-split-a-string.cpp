//1525. Number of Good Ways to Split a String
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();

        unordered_map<char, int> m1, m2;

        int result = 0;

        for (auto& c : s)
            m1[c]++;

        for (auto& c : s) {
            m1[c]--;

            if (m1[c] == 0)
                m1.erase(c);

            m2[c]++;

            if (m1.size() == m2.size())
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