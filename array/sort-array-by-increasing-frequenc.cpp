//1636. Sort Array by Increasing Frequency
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        
        for (int num : nums) {
            freq[num]++;
        }
        
        sort(nums.begin(), nums.end(), [&](const int lhs, const int rhs) {
            if (freq[lhs] == freq[rhs])
                return lhs > rhs;
            
            return freq[lhs] < freq[rhs];
        });
        
        return nums;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();