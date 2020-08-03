//1534. Count Good Triplets
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int ij = abs(arr[i] - arr[j]);
                if (ij > a) continue;
                
                for (int k = j + 1; k < n; ++k) {
                    int jk = abs(arr[j] - arr[k]);
                    int ik = abs(arr[i] - arr[k]);
                    if (jk > b || ik > c)
                        continue;
                    result++;
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