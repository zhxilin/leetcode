//1710. Maximum Units on a Truck
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[1] > rhs[1];
        });
        
        int result = 0;
        for (auto& p : boxTypes) {
            if (truckSize <= 0)
                break;
            result += min(p[0], truckSize) * p[1];
            truckSize -= p[0];
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