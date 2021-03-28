//503. Next Greater Element II
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; --i) {
            st.push(nums[i]);
        }
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] >= st.top()) 
                st.pop();
            
            if (st.empty())
                result[i] = -1;
            else 
                result[i] = st.top();
            
            st.push(nums[i]);
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