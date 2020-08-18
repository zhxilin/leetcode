//1471. The k Strongest Values in an Array
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {        
        vector<int> result;
        
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int median = arr[(n - 1) / 2];
        
        //注意题目要找top k个stronger数
        int i = 0, j = n - 1;
        while (k--) {
            if (abs(arr[i] - median) > abs(arr[j] - median))
                result.push_back(arr[i++]);
            else
                result.push_back(arr[j--]);
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