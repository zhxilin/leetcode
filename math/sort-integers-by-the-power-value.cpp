//1387. Sort Integers by The Power Value
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> vec;
        for (int i = lo; i <= hi; ++i) {
            int x = i;
            int power = 0;
            while (x != 1) {
                x = x % 2 == 0 ? x / 2 : 3 * x + 1;
                power++;
            }
            vec.push_back({i, power});
        }
        
        sort(vec.begin(), vec.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            if (lhs.second == rhs.second)
                return lhs.first < rhs.first;
            return lhs.second < rhs.second;
        });
        return vec[k - 1].first;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();