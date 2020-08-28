//769. Max Chunks To Make Sorted
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int result = 0, maximum = INT_MIN;
        for (int i = 0; i < arr.size(); ++i) {
            maximum = max(maximum, arr[i]);
            if (maximum == i) {
                result++;
                maximum = INT_MIN;
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