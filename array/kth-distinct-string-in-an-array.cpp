//2053. Kth Distinct String in an Array
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mx;
        
        
        for (auto& str : arr) {
            mx[str]++;
        }
        
        int i = 0;
        for (auto& str : arr) {
            if (mx[str] > 1)
                continue;
            
            ++i;
            
            if (i == k)
                return str;
        }
        
        return "";
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();