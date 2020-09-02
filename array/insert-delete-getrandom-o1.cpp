//380. Insert Delete GetRandom O(1)
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mx.count(val)) return false;
        
        mx[val] = mv.size();
        mv.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!mx.count(val)) return false;
        
        swap(mv[mx[val]], mv.back());
        //更新被交换元素的索引
        mx[mv[mx[val]]] = mx[val];
        
        mx.erase(val);
        mv.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int low = 0, high = mx.size() - 1;
        int idx = uniform_int_distribution<int>{low, high}(mGen);
        return mv[idx];
    }

private:
    unordered_map<int, int> mx; //<值,在vector中的索引>
    vector<int> mv;
    default_random_engine mGen;
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */