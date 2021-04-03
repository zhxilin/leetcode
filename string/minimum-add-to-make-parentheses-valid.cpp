//921. Minimum Add to Make Parentheses Valid
class Solution {
public:
    int minAddToMakeValid(string S) {
        vector<char> vec;
        int n = S.size();
        for (int i = 0; i < n; ++i) {
            if (vec.empty())
                vec.push_back(S[i]);
            else {
                if (vec.back() == '(' && S[i] == ')')
                    vec.pop_back();
                else
                    vec.push_back(S[i]);
            }
        }
        
        return vec.size();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();