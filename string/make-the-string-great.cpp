//1544. Make The String Great
class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> st;
        
        for (int i = 0; i < n; ++i) {
            if (!st.empty() && (s[i] == st.top() - 'a' + 'A' || s[i] == st.top() - 'A' + 'a'))
                st.pop();
            else
                st.push(s[i]);
        }
        
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();