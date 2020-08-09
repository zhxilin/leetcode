//1539. Kth Missing Positive Number
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int n = 1, i = 0; n <= 1000; ++n) {
            if (i < arr.size() && arr[i] == n)
                ++i;
            else if (--k == 0)
                return n;
        }
        return 1000 + k;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();