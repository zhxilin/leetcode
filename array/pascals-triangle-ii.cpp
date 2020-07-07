//119. Pascal's Triangle II
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //杨辉三角每一行的数值为C(n, 0), C(n, 1), ..., C(n, n)
        //又C(n, k) = C(n, k - 1) * (n - k + 1) / k
        vector<int> result = {1};
        
        for (int i = 1; i <= rowIndex; ++i) {
            result.push_back((long)result.back() * (rowIndex - i + 1) / i);
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