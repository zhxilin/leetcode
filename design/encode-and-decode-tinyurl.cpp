//535. Encode and Decode TinyURL
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (mLongDb.count(longUrl))
            return mBase + mLongDb[longUrl];
        
        string code;
        while (1) {
            code = produce();
            if (!mLongDb.count(code))
                break;
            code = "";
        }
        
        string tiny = mBase + code;
        mLongDb[longUrl] = code;
        mShortDb[tiny] = longUrl;
        
        return tiny;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mShortDb[shortUrl];
    }

private:
    string produce() {
        string code;
        for (int i = 0; i < 6; ++i) {
            code += mAlpha[rand() % mAlpha.size()];
        }
        return code;
    }
    
    unordered_map<string, string> mLongDb;
    unordered_map<string, string> mShortDb;
    const string mBase = "http://tinyurl.com/";
    const string mAlpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));