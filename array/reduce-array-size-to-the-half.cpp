//1338. Reduce Array Size to The Half
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size = arr.size(), halfSize = size / 2;
        
        unordered_map<int, int> mx;
        for (int num : arr) {
            mx[num]++;
        }
        
        vector<int> cnts;
        for (auto pair : mx) {
            cnts.push_back(pair.second);
        }
        sort(cnts.begin(), cnts.end(), greater<int>());
        
        int result = 0, left = size;
        for (int cnt : cnts) {
            left -= cnt;
            result++;
            if (left <= halfSize)
                break;
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