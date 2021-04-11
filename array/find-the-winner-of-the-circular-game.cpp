//1823. Find the Winner of the Circular Game
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }
        
        while (q.size() > 1) {
            for (int i = 0; i < k - 1; ++i) {
                int t = q.front();
                q.pop();
                q.push(t);
            }
            q.pop();
        }
        
        return q.front();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();