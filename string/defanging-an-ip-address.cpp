//1108. Defanging an IP Address
class Solution {
public:
    string defangIPaddr(string address) {
        stringstream ss;
        for (int i = 0; i < address.size(); ++i) {
            if (address[i] == '.')
                ss << "[.]";
            else
                ss << address[i];
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