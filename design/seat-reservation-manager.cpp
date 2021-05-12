//1845. Seat Reservation Manager
class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <=n; ++i) {
            heap.push(i);
        }
    }
    
    int reserve() {
        int seat = heap.top();
        heap.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        heap.push(seatNumber);
    }

private:
    priority_queue<int, vector<int>, greater<int>> heap;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();