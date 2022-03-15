//1116. Print Zero Even Odd
class ZeroEvenOdd {
private:
    int n;
    int state;
    
    std::condition_variable cv;
    std::mutex mtx;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->state = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        std::unique_lock lck(mtx);
        for (int i = 0; i < n; i++) {
            cv.wait(lck, [this]() { return state == 0 || state == 2; });
            printNumber(0);
            
            ++state %= 4;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        std::unique_lock lck(mtx);
        for (int i = 2; i <= n; i += 2) {
            cv.wait(lck, [this]() { return state == 3; });
            printNumber(i);
            
            ++state %= 4;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        std::unique_lock lck(mtx);
        for (int i = 1; i <= n; i += 2) {
            cv.wait(lck, [this]() { return state == 1; });
            printNumber(i);
            
            ++state %= 4;
            cv.notify_all();
        }
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();