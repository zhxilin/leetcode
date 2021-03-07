//961. N-Repeated Element in Size 2N Array
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int> cnts;
        for (auto& n : A) {
            cnts[n]++;
        }
        
        int n = A.size() / 2;
        
        for (auto it = cnts.begin(); it != cnts.end(); ++it) {
            if (it->second == n) {
                return it->first;
            }
        }
        return 0;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();