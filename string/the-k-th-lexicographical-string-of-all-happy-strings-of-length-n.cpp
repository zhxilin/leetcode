//1415. The k-th Lexicographical String of All Happy Strings of Length n
class Solution {
public:
    string getHappyString(int n, int k) {
        vector<char> letters{'a', 'b', 'c'};
        vector<string> result;
        
        backtrack(letters, "", 0, n, result);
        
        if (k > result.size())
            return "";
        
        sort(result.begin(), result.end());
        
        return result[k - 1];
    }
    
private:
    void backtrack(const vector<char>& letters, string cur, int pos, int n, vector<string>& result) {
        if (pos == n) {
            result.push_back(cur);
            return;
        }
        
        for (int i = 0; i < letters.size(); ++i) {
            if (pos == 0 || letters[i] != cur[pos - 1]) {
                cur.push_back(letters[i]);
                backtrack(letters, cur, pos + 1, n, result);
                cur.pop_back();
            }
        }
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();