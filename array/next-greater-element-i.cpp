//496. Next Greater Element I
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        stack<int> st;
        unordered_map<int, int> mx;
        
        //find NGN for each value in nums2
        for (int n : nums2) {
            if (st.empty()) {
                st.push(n);
                continue;
            }
            
            while (!st.empty() && n > st.top()) {
                mx[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        
        while (!st.empty()) {
            mx[st.top()] = -1;
            st.pop();
        }
        
        for (int n : nums1) {
            result.push_back(mx[n]);
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