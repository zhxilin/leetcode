//763. Partition Labels
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        vector<int> last(26);
        for (int i = 0; i < n; ++i) {
            last[S[i] - 'a'] = i;
        }
        
        vector<int> result;
        int start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            end = max(end, last[S[i] - 'a']);
            if (i == end) {
                result.push_back(i - start + 1);
                start = i + 1;
            }
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