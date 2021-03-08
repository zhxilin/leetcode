//811. Subdomain Visit Count
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> freq;
        for (const string& str : cpdomains) {
            stringstream ss(str);
            int count = 0;
            ss >> count;
            
            string domain;
            ss >> domain;
            
            while (!domain.empty()) {
                freq[domain] += count;
                size_t dot = domain.find_first_of(".");
                domain = (dot != std::string::npos) ? domain.substr(dot + 1) : "";
            }
        }
        
        vector<string> result;
        for (auto& it : freq) {
            string cur = to_string(it.second) + ' ' + it.first;
            result.push_back(cur);
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