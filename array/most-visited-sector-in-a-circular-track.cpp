//1560. Most Visited Sector in a Circular Track
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        
        //若start <= end, 范围为[start, end]
        //若end < start, 范围为[1, end] + range [start, n]
        int size = rounds.size();
        
        vector<int> result;
        
        if (rounds[0] <= rounds[size - 1]) {
            for (int i = rounds[0]; i <= rounds[size - 1]; ++i)
                result.push_back(i);
            
            return result;
        }
        
        for (int i = 1; i <= rounds[size - 1]; ++i)
            result.push_back(i);
        
        for (int i = rounds[0]; i <= n; ++i)
            result.push_back(i);
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();