//1111. Maximum Nesting Depth of Two Valid Parentheses Strings
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> result(n);
        vector<int> st;
        
        for (int i = 0; i < n; ++i) {
            if (st.empty() || seq[i] == '(') {
                st.push_back(seq[i]);
                result[i] = st.size() % 2;
            } else {
                result[i] = st.size() % 2;
                st.pop_back();
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