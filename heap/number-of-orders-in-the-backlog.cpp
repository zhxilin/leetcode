//1801. Number of Orders in the Backlog
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        //buy_heap: max heap
        //sell_heap: min heap
        priority_queue<vector<int>> buy_heap, sell_heap;
        
        for (auto& order : orders) {
            int price = order[0];
            int amount = order[1];
            int type = order[2];
            
            if (0 == type)
                buy_heap.push({price, amount});
            else
                sell_heap.push({-price, amount});//notice! -price will make it as a min heap. no need to define a comparor
            
            while (!sell_heap.empty() && !buy_heap.empty() && -sell_heap.top()[0] <= buy_heap.top()[0]) {
                auto itemSell = sell_heap.top();
                sell_heap.pop();
                
                auto itemBuy = buy_heap.top();
                buy_heap.pop();
                
                int soldCount = min(itemSell[1], itemBuy[1]);
                
                if (itemSell[1] > soldCount)
                    sell_heap.push({itemSell[0], itemSell[1] - soldCount});
                
                if (itemBuy[1] > soldCount)
                    buy_heap.push({itemBuy[0], itemBuy[1] - soldCount});
            }
        }
        
        long result = 0;
        while (!buy_heap.empty()) {
            result += buy_heap.top()[1];
            buy_heap.pop();
        }
        while (!sell_heap.empty()) {
            result += sell_heap.top()[1];
            sell_heap.pop();
        }
        
        return result % 1000000007;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();