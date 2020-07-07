//1010. Pairs of Songs With Total Durations Divisible by 60
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        vector<int> v(60, 0);
        
        for (int i = 0; i < time.size(); ++i) {
            int t = time[i] % 60;
            if (0 == t) 
                result += v[t];
            else 
                result += v[60 - t];
            
            v[t]++;
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