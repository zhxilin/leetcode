//1109. Corporate Flight Bookings
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> result(n + 1);
        
        for (auto& b : bookings) {
            result[b[0] - 1] += b[2];
            result[b[1]] -= b[2];
        }
        
        for (int i = 1; i <= n; ++i) {
            result[i] += result[i - 1];
        }
        
        result.pop_back();
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();