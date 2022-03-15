//1115. Print FooBar Alternately
class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            {
                std::unique_lock lck(mtx);
                while (flag) cv.wait(lck);

                printFoo();

                flag = true;
            }
            
            cv.notify_all();            
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            {
                std::unique_lock lck(mtx);
                while (!flag) cv.wait(lck);

                printBar();            

                flag = false;
            }
            
            cv.notify_all();            
        }
    }

private:
    atomic<bool> flag;
    std::mutex mtx;
    std::condition_variable cv;
};

static auto _ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();