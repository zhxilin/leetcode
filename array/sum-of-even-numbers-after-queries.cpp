//985. Sum of Even Numbers After Queries
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> result;
        
        //先计算原数组偶数的和
        int sum = 0;
        for (int num : A) {
            if (0 == num % 2)
                sum += num;
        }
        
        for (auto query : queries) {
            int val = query[0];
            int index = query[1];
            
            //原值若为偶数,和先减掉,修改之后如果还为偶数则加上新值,不必没轮都重新求和
            if (0 == A[index] % 2)
                sum -= A[index];
            
            A[index] += val;            
            
            if (0 == A[index] % 2)
                sum += A[index];
            
            result.push_back(sum);
        }
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();