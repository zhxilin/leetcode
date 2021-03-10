//1441. Build an Array With Stack Operations
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        
        for (int i = 0, j = 1; i < target.size() && j <= n; ) {
            if (target[i] == j) {
                result.push_back("Push");
                i++, j++;
            } else {
                result.push_back("Push");
                result.push_back("Pop");
                j++;
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