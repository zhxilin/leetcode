//1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, result = 0, size = arr.size();
        
		for (int i = 0; i < size; ++i) {
			sum += arr[i];
			if (i >= k)
                sum -= arr[i - k]; //保持最新的k个元素之和
            
			if (sum >= threshold * k && i >= k - 1) 
                result++;
		}
		return result;
    }
};

static auto _= []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();