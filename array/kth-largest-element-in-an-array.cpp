//215. Kth Largest Element in an Array
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min_heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; ++i) {
            pq.push(nums[i]);
        }

        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] >= pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();