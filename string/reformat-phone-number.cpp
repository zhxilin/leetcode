//1694. Reformat Phone Number
class Solution {
public:
    string reformatNumber(string number) {
        int n = number.size();
        int blocklen = 0;
        string p;
        for (auto& c : number) {
            if (c == ' ' || c == '-')
                continue;
            
            if (blocklen > 0 && blocklen % 3 == 0)
                p += '-';
            
            p += c;
            blocklen++;
        }
        
        int len = p.size();
        if (p[len - 2] == '-')
            swap(p[len - 2], p[len - 3]);
        
        return p;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();