//1829. Maximum XOR for Each Query
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prefix;

        int pre = nums[0];
        prefix.push_back(pre);

        for (int i = 1; i < n; ++i) {
            int t = pre ^ nums[i];
            prefix.push_back(t);
            pre = t;
        }

        int max = pow(2, maximumBit) - 1;

        vector<int> result;
        for (int i = n - 1; i >=0; --i) {
            int t = max ^ prefix[i];
            result.push_back(t);
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