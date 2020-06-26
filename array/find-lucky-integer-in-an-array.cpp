//1394. Find Lucky Integer in an Array
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mx;
        for (int num : arr) {
            mx[num]++;
        }
        
        int result = -1;
        for (auto itr = mx.begin(); itr != mx.end(); ++itr) {
            if (itr->first == itr->second)
                result = max(result, itr->second);
        }
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();