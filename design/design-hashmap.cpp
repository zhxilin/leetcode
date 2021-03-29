//706. Design HashMap
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        kvs.resize(1000001, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        kvs[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return kvs[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        kvs[key] = -1;
    }

private:
    vector<int> kvs;
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */