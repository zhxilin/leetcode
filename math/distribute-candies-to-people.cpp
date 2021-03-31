//1103. Distribute Candies to People
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people);
        
        int index = 1, candy = 1;
        while (candies) {
            int candy = min(candies, candy + 1);
            result[index - 1] += candy;
            candies -= candy;
            
            if (index % num_people == 0)
                index = 1;
            else
                index++;
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