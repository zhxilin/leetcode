//1047. Remove All Adjacent Duplicates In String
class Solution {
public:
    string removeDuplicates(string S) {
        if (S.empty()) 
            return "";
        
        stack<char> stack;
        
        for (int i = 0; i < S.size(); ++i) {
            if (stack.empty() || S[i] != stack.top())
                stack.push(S[i]);
            else
                stack.pop();
        }
        
        string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
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