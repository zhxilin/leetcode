//1195. Fizz Buzz Multithreaded
class FizzBuzz {
public:
    FizzBuzz(int n) : n(n), counter(std::atomic(0)) {
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        run([](int i) { return i % 3 == 0 && i % 5 != 0; },
           [&](int i) { printFizz(); });
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        run([](int i) { return i % 3 != 0 && i % 5 == 0; },
           [&](int i) { printBuzz(); });
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {        
        run([](int i) { return i % 3 == 0 && i % 5 == 0; },
           [&](int i) { printFizzBuzz(); });
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {        
        run([](int i) { return i % 3 != 0 && i % 5 != 0; },
            printNumber);
    }
    
private:
    void run(function<bool(int)> cond, function<void(int)> print) {
        for (int i = 1; i <= n; ++i) {
            if (cond(i)) {
                print(i);
            }
            
            if (++counter == 4) {
                counter.store(0);
                next.notify_all();
            } else {
                std::unique_lock<std::mutex> lock(mutex);
                next.wait(lock);
            }
        }
    }

private:
    int n;

    std::atomic<int> counter;
    std::mutex mutex;
    std::condition_variable next;
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();