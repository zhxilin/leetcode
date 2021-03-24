//1114. Print in Order
class Foo {
public:
    Foo() {
        f1 = p1.get_future();
        f2 = p2.get_future();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        p1.set_value();
    }

    void second(function<void()> printSecond) {
        f1.wait();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        p2.set_value();
    }

    void third(function<void()> printThird) {
        f2.wait();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    std::promise<void> p1;
    std::promise<void> p2;
    std::future<void> f1;
    std::future<void> f2;
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();