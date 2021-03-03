//1656. Design an Ordered Stream
class OrderedStream {
public:
    OrderedStream(int n) : mData(n), mCurPos(0) {
        
    }
    
    vector<string> insert(int idKey, string value) {
        mData[idKey - 1] = value;
        
        int prevPos = mCurPos;
        mCurPos = nextPos();
        
        return vector<string>(mData.begin() + prevPos, mData.begin() + mCurPos);
    }

private:
    int nextPos() {
        for (int i = 0; i < mData.size(); ++i) {
            if (mData[i].empty())
                return i;
        }
        return mData.size();
    }

private:
    vector<string> mData;
    int mCurPos; 
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */