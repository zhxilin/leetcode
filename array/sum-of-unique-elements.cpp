//1748. Sum of Unique Elements
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int, int> cnts;
        for (auto& num : nums) {
            cnts[num]++;
        }
        
        int result = 0;
        for (auto it = cnts.begin(); it != cnts.end(); ++it) {
            if (it->second == 1)
                result += it->first;
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