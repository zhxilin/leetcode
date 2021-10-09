//146. LRU Cache
class LRUCache {
public:
    LRUCache(int capacity) : m_cap(capacity) {
    }

    int get(int key) {
        auto it = m_map.find(key);
        if (it == m_map.end())
            return -1;

        //move the item to head
        m_list.splice(m_list.begin(), m_list, it->second);

        return it->second->second;
    }

    void put(int key, int value) {
        auto it = m_map.find(key);
        if (it != m_map.end()) {
            //update value
            it->second->second = value;
            //move the item to head
            m_list.splice(m_list.begin(), m_list, it->second);
            return;
        }

        if (m_list.size() >= m_cap) {
            //remove lru item
            auto itLRU = m_list.back();
            m_map.erase(itLRU.first);
            m_list.pop_back();
        }

        m_list.emplace_front(key, value);
        m_map[key] = m_list.begin();
    }

private:
    using node = pair<int, int>;
    using iterator = list<node>::iterator;

    unordered_map<int, iterator> m_map;
    list<node> m_list;
    int m_cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();