//1170. Compare Strings by Frequency of the Smallest Character
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> result;
        vector<int> wCnts;
        
        for (const string& word : words) {          
            wCnts.push_back(f(word));
        }
        
        sort(wCnts.begin(), wCnts.end());
        
        for (const string& query : queries) {
            int cnt = f(query);                        
            int freq = wCnts.end() - upper_bound(wCnts.begin(), wCnts.end(), cnt);
            result.push_back(freq);
        }
        
        return result;
    }
    
private:
    int f(string s) {
        char min = 'z';
        int count = 0;
        
        for (char c : s) {
            if (c == min)
                count++;
            else if (c < min) {
                count = 1;
                min = c;
            }
        }
        return count;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();