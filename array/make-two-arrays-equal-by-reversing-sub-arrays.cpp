//1460. Make Two Arrays Equal by Reversing Sub-arrays
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() != arr.size()) return false;
        
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < target.size(); ++i) {
            if (target[i] != arr[i])
                return false;
        }
        
        return true;
    }
};

static auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();