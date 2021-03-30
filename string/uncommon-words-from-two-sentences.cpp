//884. Uncommon Words from Two Sentences
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> mx;
        
        parse(A, mx);
        parse(B, mx);

        vector<string> result;
        for (auto& p : mx) {
            if (p.second == 1)
                result.push_back(p.first);
        }
        return result;
    }

private:
    void parse(const string& str, unordered_map<string, int>& map) {
        stringstream ss(str);
        string item;
        while (getline(ss, item, ' ')) {
            if (map.count(item))
                map[item]--;
            else
                map[item] = 1;
        }
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();