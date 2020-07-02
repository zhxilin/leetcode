//1184. Distance Between Bus Stops
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        
        int total = std::accumulate(distance.begin(), distance.end(), 0);
        int dist = 0;
        for (int i = min(start, destination); i < max(start, destination); ++i) {
            dist += distance[i];
        }
        
        return min(dist, total - dist);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();