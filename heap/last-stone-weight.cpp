//1046. Last Stone Weight
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;//max-heap
        for (int stone : stones) {
            heap.push(stone);
        }
        
        while (heap.size() > 1) {
            int y = heap.top(); heap.pop();
            int x = heap.top(); heap.pop();

            int w = y - x;
            if (w > 0)
                heap.push(w);
        }
        
        return heap.empty() ? 0 : heap.top();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();