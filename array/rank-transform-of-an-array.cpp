//1331. Rank Transform of an Array
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        
        unordered_map<int, int> mx;
        int rank = 1;
        
        for (int num : s) {
            mx[num] = rank++;
        }
        
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = mx[arr[i]];
        }
        return arr;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();