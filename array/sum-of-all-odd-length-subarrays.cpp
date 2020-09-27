//1588. Sum of All Odd Length Subarrays
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            int sum = arr[i];            
            result += sum;
            
            for (int j = i + 1; j < n; ++j) {
                sum += arr[j];
                
                if ((j - i + 1) % 2 == 1)
                    result += sum;
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