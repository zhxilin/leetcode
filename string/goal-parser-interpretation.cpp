//1678. Goal Parser Interpretation
class Solution {
public:
    string interpret(string command) {
        stringstream ss;
        
        for (int i = 0; i <= command.size() - 1; ) {
            if (command[i] == 'G') {
                ss << "G";
                ++i;
            } else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    ss << "o";
                    i += 2;
                } else if (command[i + 1] == 'a') {
                    ss << "al";
                    i += 4;
                }
            }
        }
        
        return ss.str();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();