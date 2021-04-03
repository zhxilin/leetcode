//917. Reverse Only Letters
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int head = 0, last = S.size() - 1;
        while (head < last) {
            while (head < last && !isalpha(S[head]))
                head++;
            while (head < last && !isalpha(S[last]))
                last--;
            
            swap(S[head], S[last]);
            head++;
            last--;
        }
        
        return S;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();