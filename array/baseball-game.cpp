//682. Baseball Game
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        
        for (const auto& op : ops) {
            if (op == "+")
                record.push_back(record[record.size() - 1] + record[record.size() - 2]);
            else if (op == "D")
                record.push_back(record.back() * 2);       
            else if (op == "C")
                record.pop_back();
            else
                record.push_back(std::stoi(op));
        }
        
        int sum = accumulate(record.begin(), record.end(), 0);
        return sum;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();