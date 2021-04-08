//1286. Iterator for Combination
class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) : mCurIndex(0) {
        generate(characters, combinationLength, "", 0);
    }
    
    string next() {
        if (mCurIndex > mCom.size())
            return "";
        
        return mCom[mCurIndex++];
    }
    
    bool hasNext() {
        return mCurIndex < mCom.size();
    }

private:
    void generate(const string& characters, int len, const std::string& str, int start) {
        if (len == 0) {
            mCom.push_back(std::move(str));
            return;
        }
        
        for (int i = start; i < characters.size(); ++i) {
            generate(characters, len - 1, str + characters[i], i + 1);
        }
    }

private:
    vector<string> mCom;
    int mCurIndex;
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */