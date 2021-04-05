//1472. Design Browser History
class BrowserHistory {
public:
    BrowserHistory(string homepage) : mCurIndex(0) {
        mHistory.push_back(homepage);
    }
    
    void visit(string url) {
        int n = mHistory.size();
        if (mCurIndex < n - 1)
            mHistory.erase(mHistory.begin() + mCurIndex + 1, mHistory.end());
        
        mHistory.push_back(url);            
        mCurIndex = mHistory.size() - 1;
    }
    
    string back(int steps) {
        if (mHistory.empty()) 
            return "";
        
        if (mCurIndex - steps > 0)
            mCurIndex -= steps;
        else
            mCurIndex = 0;
        
        return mHistory[mCurIndex];
    }
    
    string forward(int steps) {
        if (mHistory.empty())
            return "";
       
        int n = mHistory.size();
        if (mCurIndex + steps > n - 1)
            mCurIndex = n - 1;
        else
            mCurIndex += steps;
        
        return mHistory[mCurIndex];
    }
    
private:
    vector<string> mHistory;
    int mCurIndex;
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */