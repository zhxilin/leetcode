//1518. Water Bottles
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int bottles(numBottles);
        
        int result = bottles;
        while (bottles >= numExchange) {
            int newBottles = bottles / numExchange;
            bottles = bottles % numExchange + newBottles;
            result += newBottles;
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