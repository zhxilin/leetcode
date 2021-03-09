//944. Delete Columns to Make Sorted
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int result = 0;
        int len = strs[0].size();
        
        for (int j = 0; j < len; ++j) {
            for (int i = 0; i < strs.size() - 1; ++i) {
                if (strs[i][j] > strs[i + 1][j]) {
                    result++;
                    break;
                }
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
};