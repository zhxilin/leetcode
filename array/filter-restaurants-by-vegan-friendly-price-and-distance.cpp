//1333. Filter Restaurants by Vegan-Friendly, Price and Distance
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> res; //<rating, id>
        for (auto restaurant : restaurants) {
            if (restaurant[2] < veganFriendly || 
                restaurant[3] > maxPrice || 
                restaurant[4] > maxDistance)
                continue;
            
            res.push_back({restaurant[1], restaurant[0]});
        }
        
        sort(res.begin(), res.end(), greater());
        
        vector<int> result;
        
        for (auto pair : res) {
            result.emplace_back(pair.second);
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