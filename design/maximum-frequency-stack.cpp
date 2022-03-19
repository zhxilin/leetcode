//895. Maximum Frequency Stack
class FreqStack {
public:
    FreqStack() : curTerm(0) {

    }

    void push(int val) {
        int freq = 0;
        if (mx.count(val))
            freq = ++mx[val];
        else {
            freq = 1;
            mx[val] = freq;
        }

        Node node(val, curTerm++, freq);
        mq.push(node);
    }

    int pop() {
        if (mq.empty()) return -1;

        Node node = mq.top();
        mq.pop();

        mx[node.Val]--;

        if (mx[node.Val] <= 0)
            mx.erase(node.Val);

        return node.Val;
    }

private:
    struct Node {
        int Val;
        int Term;
        int Freq;
        Node(int v, int t, int f) : Val(v), Term(t), Freq(f) {}
    };

    struct NodeComparor {
        bool operator()(const Node& lhs, const Node& rhs) {
            if (lhs.Freq == rhs.Freq)
                return lhs.Term < rhs.Term;

            return lhs.Freq < rhs.Freq;
        }
    };

    priority_queue<Node, vector<Node>, NodeComparor> mq; //min-heap
    unordered_map<int, int> mx; //<val, freq>

    int curTerm;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */