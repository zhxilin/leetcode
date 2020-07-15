//1346. Check If N and Its Double Exist
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::unordered_map<int, int> mx;
        for (int i = 0; i < arr.size(); ++i) {
            mx[arr[i]] = i;
        }
        
        for (int i = 0; i < arr.size(); ++i) {
            int twice = arr[i] * 2;
            if (mx.count(twice) && i != mx[twice])
                return true;
        }
        
        return false;
    }
};

static auto _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();