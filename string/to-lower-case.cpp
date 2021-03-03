//709. To Lower Case
class Solution {
public:
    string toLowerCase(string str) {        
        for(char& c: str) {
            if ('A' <= c && c <= 'Z')
                c += 32;
        }

        return str;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();