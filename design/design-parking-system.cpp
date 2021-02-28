//1603. Design Parking System
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        lots.push_back(big);
        lots.push_back(medium);
        lots.push_back(small);
    }
    
    bool addCar(int carType) {
        return lots[carType - 1]-- > 0;
    }

private:
    vector<int> lots;
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */