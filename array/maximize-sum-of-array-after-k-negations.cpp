//1005. Maximize Sum Of Array After K Negations
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int>> q; //min heap
        for (int num : A) {
            q.push(num);
        }
        
        for (int i = 0; i < K; ++i) {
            int t = q.top();
            t = -t;
            q.pop();
            q.push(t);
        }
        
        int result = 0;
        while (!q.empty()) {
            result += q.top();
            q.pop();
        }
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();