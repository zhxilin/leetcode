//1018. Binary Prefix Divisible By 5
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> result;
        
        int num = 0;
        for (int a : A) {
            num = ((num << 1) | a) % 5;
            result.push_back(0 == num % 5);
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