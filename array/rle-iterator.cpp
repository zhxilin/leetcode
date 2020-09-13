//900. RLE Iterator
class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        for(int i = 0; i < A.size() - 1; i += 2) {
            cache.push_back({A[i], A[i+1]});
        }
    }
    
    int next(int n) {
        if (cache.empty())
            return -1;
        
        auto front = cache.front();
        cache.pop_front();
        
        if (n < front.first) {
            front.first -= n;
            cache.push_front(front);
            return front.second;
        }
        
        if (n == front.first)
            return front.second;
            
        return next(n - front.first);
    }
    
private:
    deque<pair<int,int>> cache; 
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */