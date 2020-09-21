//729. My Calendar I
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        return s.insert({start, end}).second;
    }

private:
    using Event = pair<int, int>;
    
    struct EventComparor {
        bool operator()(const Event& lhs, const Event& rhs) const {
            return lhs.second <= rhs.first;
        }
    };
    
    set<Event, EventComparor> s;
    
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */