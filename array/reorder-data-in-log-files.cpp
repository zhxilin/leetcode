//937. Reorder Data in Log Files
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letters, digits, result;
        
        for (const string& s : logs) {
            int pos = s.find_first_of(" ");
            if (isalpha(s[pos + 1])) 
                letters.push_back(s);
            else 
                digits.push_back(s);
        }
        
        sort(letters.begin(), letters.end(), [](const string& lhs, const string& rhs) {
            int pl = lhs.find_first_of(" "), pr = rhs.find_first_of(" ");
            string idl = lhs.substr(0, pl);
            string idr = rhs.substr(0, pr);
            string cl = lhs.substr(pl + 1, lhs.size() - pl);
            string cr = rhs.substr(pr + 1, rhs.size() - pr);
            
            return cl == cr ? idl < idr : cl < cr;
        });
        
        for (const string& s : letters) {
            result.push_back(move(s));
        }
        
        for (const string& s : digits) {
            result.push_back(move(s));
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
