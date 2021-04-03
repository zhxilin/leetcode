//1640. Check Array Formation Through Concatenation
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> mx;
        for (auto& p : pieces) {
            mx[p[0]] = p;
        }
                
        for (int i = 0; i < arr.size(); ) {
            int v = arr[i];
            if (!mx.count(v))
                return false;
            
            for (int e : mx[v]) {
                if (e != arr[i])
                    return false;
                
                i++;
            }
        }
        
        return true;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();