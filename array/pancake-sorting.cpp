//969. Pancake Sorting
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size(), i = n - 1;
        int up = A[n - 1];
        
        vector<int> result;
        
        //每次迭代需保证A[i]不小于开头，且不大于后一个元素
        //如果不满足，则需要从开头翻转到当前位置，然后重置计数，再来一次迭代
        while (i != 0) {
            if (A[i] >= A[0] && A[i] <= up)
                up = A[i--];
            else { 
                result.push_back(i + 1);
                reverse(A.begin(), A.begin() + i + 1);
                
                i = n - 1;
                up = A[n - 1];
            }
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