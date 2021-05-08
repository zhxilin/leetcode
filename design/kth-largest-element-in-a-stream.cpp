//703. Kth Largest Element in a Stream
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        mk = k;
        //最小堆,只保存最大的k个元素,堆头即为第k个最大值
        for (int n : nums) {
            mq.push(n);
            if (mq.size() > k)
                mq.pop();
        }
    }
    
    int add(int val) {
        mq.push(val); 
        if (mq.size() > mk) 
            mq.pop();
        return mq.top(); 
    }

private:
    int mk;
    priority_queue<int, vector<int>, greater<int>> mq; //min_heap
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();