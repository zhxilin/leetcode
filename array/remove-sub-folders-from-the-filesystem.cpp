//1233. Remove Sub-Folders from the Filesystem
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> result;        
        result.push_back(folder[0]);

        for (int i = 1; i < folder.size(); ++i) {
        string f = folder[i];
        
        if (f.find(result.back()) != 0)
            result.push_back(f);
        else if (f[result.back().length()] != '/') //要区分/a/b/c和/a/b/ca
            result.push_back(f);
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
