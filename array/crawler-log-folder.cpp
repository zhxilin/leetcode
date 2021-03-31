//1598. Crawler Log Folder
class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> dirs;
        for (const string& log : logs) {
            if (log == "../") {
                if (dirs.empty())
                    continue;
                dirs.pop_back();
            } else if (log == "./")
                continue;
            else
                dirs.push_back(log);
        }
        return dirs.size();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;  
};