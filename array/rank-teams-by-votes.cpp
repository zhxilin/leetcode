//1366. Rank Teams by Votes
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<Element> v(26);
        
        int n = votes[0].size();
        
        for (int i = 0; i < v.size(); ++i) {
            v[i].c = 'A' + i;
            v[i].rank.resize(n);
        }
        
        for (const string& vote : votes) {
            for (int i = 0; i < vote.size(); ++i)
                v[vote[i] - 'A'].rank[i]++;
        }
        
        sort(v.begin(), v.end());
        
        stringstream ss;
        
        for (const Element& data : v) 
            ss << data.c;
        
        return ss.str().substr(0, n);
    }
    
    struct Element {
        vector<int> rank;
        char c;
        
        bool operator<(const Element& rhs) const {
            for (int i = 0; i < rank.size(); ++i) {
                if (rank[i] != rhs.rank[i]) 
                    return rank[i] > rhs.rank[i];
            }
            
            return c < rhs.c;
        }
    };
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();