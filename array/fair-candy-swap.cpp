//888. Fair Candy Swap
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0, sumB = 0;
        
        unordered_set<int> s;
        
        for (int a : A) sumA += a;
        for (int b : B) {
            sumB += b;
            s.insert(b);
        }
        
        //sumA - x + y = sumb - y + x
        //y = x + (sumB - sumA) / 2
        
        int delta = (sumB - sumA) / 2;
        
        for (int a : A) {
            if (s.count(a + delta))
                return {a, a + delta};
        }
        
        return {};
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();