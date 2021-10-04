//225. Implement Stack using Queues
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        mq.push_front(x);
    }
    
    int pop() {
        int t = mq.front();
        mq.pop_front();
        return t;
    }
    
    int top() {
        return mq.front();
    }
    
    bool empty() {
        return mq.empty();
    }

private:
    deque<int> mq;
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */