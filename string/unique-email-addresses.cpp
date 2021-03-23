class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_set<string> mx;
        
        for (auto& email : emails) {
            
            vector<string> vec = split(email, '@');
            if (vec.size() != 2)
                continue;
            
            string local;
            for (auto& c : vec[0]) {
                if (c == '.')
                    continue;
                if (c == '+')
                    break;
                local += c;
            }
            
            mx.insert(local + '@' + vec[1]);
        }
        
        return mx.size();
    }
    
private:
    vector<string> split(const std::string &s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> elems;
        while (getline(ss, item, delim)) {
            elems.push_back(std::move(item));
        }
        return std::move(elems);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();