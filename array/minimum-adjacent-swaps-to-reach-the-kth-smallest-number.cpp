class Solution {
public:
    int getMinSwaps(string num, int k) {
        string str = num;

        while (k--) {
            next_permutation(num.begin(), num.end());
        }

        int result = 0;

        for (int i = 0; i < num.size(); ++i) {
            if (num[i] != str[i]) {
                int pos = num.find(str[i], i);

                while (pos > i) {
                    swap(num[pos], num[pos - 1]);
                    result++;
                    pos--;
                }
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