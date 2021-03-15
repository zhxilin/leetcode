//1356. Sort Integers by The Number of 1 Bits
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int lhs, const int rhs) {
            int cnt1 = 0, cnt2 = 0;
            
            int v(lhs);
            while (v) {
                cnt1++;
                v &= (v - 1);
            }
            
            v = rhs;
            while (v) {
                cnt2++;
                v &= (v - 1);
            }
            
            if (cnt1 == cnt2)
                return lhs <= rhs;
            
            return cnt1 < cnt2;
        });
        
        return arr;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;  
};