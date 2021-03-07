//942. DI String Match
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        int low = 0, high = n;
        
        vector<int> result(n + 1);
        
        for (int i = 0; i < n; ++i) {
            if (S[i] == 'I') 
                result[i] = low++;
            else
                result[i] = high--;
        }
        
        result[n] = low;
        return result;
    }
};


static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();