//1442. Count Triplets That Can Form Two Arrays of Equal XOR
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        //a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
        //b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
        //若a == b, 则a ^ b == 0，因此计算arr[i] ^ arr[i + 1] ^ ... ^ arr[k] == 0时，
        //j在i到k中任意一个都可以，总数则为k - i
        
        int result = 0;
        
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            int val = arr[i];
            for (int k = i + 1; k < n; ++k) {
                val ^= arr[k];
                if (0 == val)
                    result += k - i;
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