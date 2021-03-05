//1704. Determine if String Halves Are Alike
class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int n = s.size();
        int mid = n / 2;
        
        int cntA = 0, cntB = 0;
        for (int i = 0; i < n; ++i) {
            if (i < mid) {
                if (vowels.count(s[i]))
                    cntA++;
            } else {
                if (vowels.count(s[i]))
                    cntB++;
            }
        }
        
        return cntA == cntB;
    }
    
private:
    unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();