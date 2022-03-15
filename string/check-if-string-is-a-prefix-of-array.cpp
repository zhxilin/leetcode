//1961. Check If String Is a Prefix of Array
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = s.size();
        int index = 0;
        
        for (auto& word : words) {
            if (index >= n)
                break;
            
            int size = word.size();
            if (s.substr(index, size) != word)
                return false;
            
            index += size;
        }
        
        return index >= n;
    }
};

static auto _ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();