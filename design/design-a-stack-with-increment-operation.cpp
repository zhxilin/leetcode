//1381. Design a Stack With Increment Operation
class CustomStack {
public:
    CustomStack(int maxSize) {
        mMaxSize = maxSize;
    }
    
    void push(int x) {
        if (mVec.size() < mMaxSize)
            mVec.push_back(x);
    }
    
    int pop() {
        if (mVec.empty())
            return -1;
        
        int v = mVec.back();
        mVec.pop_back();
        return v;
    }
    
    void increment(int k, int val) {
        int cnt = min(k, int(mVec.size()));
        for (int i = 0; i < cnt; ++i) {
            mVec[i] += val;
        }
    }

private:
    vector<int> mVec;
    int mMaxSize;
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */