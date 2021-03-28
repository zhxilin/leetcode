//1619. Mean of Array After Removing Some Elements
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int removeCnt = n * 0.05;
        
        double sum = accumulate(arr.begin() + removeCnt, arr.end() - removeCnt, 0.0);
        return sum / (n - 2 * removeCnt);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();