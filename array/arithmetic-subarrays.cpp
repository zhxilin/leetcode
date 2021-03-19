//1630. Arithmetic Subarrays
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> result(m);
        
        for (int i = 0; i < m; ++i) {
            int b = l[i], e = r[i];
            vector<int> sub(nums.begin() + b, nums.begin() + e + 1);
            sort(sub.begin(), sub.end());
            result[i] = checkSubarray(sub);
        }
        
        return result;
    }
    
private:
    bool checkSubarray(const vector<int>& arr) {
        if (arr.size() <= 2)
            return true;
        
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); ++i) {
            if (diff != arr[i] - arr[i - 1] )
                return false;
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