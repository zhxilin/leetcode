//1417. Reformat The String
class Solution {
public:
    string reformat(string s) {
        deque<char> letters, digits;
        for (char c : s) {
            if (isdigit(c))
                digits.push_back(c);
            else
                letters.push_back(c);
        }
        
        int ln = letters.size(), dn = digits.size();
        if (abs(ln - dn) > 1)
            return "";
        
        stringstream ss;
        if (ln > dn) {
            while (ss.str().size() != s.size()) {
                if (!letters.empty()) {
                    ss << letters.front();
                    letters.pop_front();
                }
                if (!digits.empty()) {
                    ss << digits.front();
                    digits.pop_front();
                }
            }
        } else {
            while (ss.str().size() != s.size()) {
                if (!digits.empty()) {
                    ss << digits.front();
                    digits.pop_front();
                }
                if (!letters.empty()) {
                    ss << letters.front();
                    letters.pop_front();
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