//1117. Building H2O
class H2O {
public:
    H2O() : hCnt(0), oCnt(0) {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        {
            std::unique_lock lck(mtx);
            cv.wait(lck, [this]() { return hCnt < 2; });

            releaseHydrogen();            
            hCnt++;
        }
        
        try_reset();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        {
            std::unique_lock lck(mtx);
            cv.wait(lck, [this]() { return oCnt < 1; });

            releaseOxygen();            
            oCnt++;       
        }
        
        try_reset();
        cv.notify_all();
    }

private:
    void try_reset() {
        if (hCnt == 2 && oCnt == 1)
            hCnt = oCnt = 0;
    }

private:
    int oCnt;
    int hCnt;
    
    std::mutex mtx;
    std::condition_variable cv;
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();