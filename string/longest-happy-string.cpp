//1405. Longest Happy String
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        stringstream ss;
        priority_queue<pair<int, char>> q;
        if (a > 0)
            q.push({a, 'a'});
        if (b > 0)
            q.push({b, 'b'});
        if (c > 0)
            q.push({c, 'c'});
        
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            
            char c = p.second;
            
            int size = ss.str().size();
            if (size > 1 && ss.str()[size - 1] == c && ss.str()[size - 2] == c) {
                if (q.empty()) break;
                
                auto tmp = q.top();
                q.pop();
                
                c = tmp.second;
                tmp.first--;
                if (tmp.first > 0)
                    q.push(tmp);
                
                p.first++;
            }
            
            ss << c;
            p.first--;
            
            if (p.first > 0)
                q.push(p);
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