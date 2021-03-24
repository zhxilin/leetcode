//1332. Remove Palindromic Subsequences
class Solution {
public:
    int removePalindromeSub(string s) {
        //字符串只有ab组成,如果s本身为回文,直接移除,一共只需1次移除.
        //如果s非回文,则一定可以先移除所有a的子序列,剩下全部b的子序列,一共只需要2次移除.
        //问题转化为判断s是否为回文串
        
        int n = s.size();
        
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (s[i] != s[j])
                return 2;
        }
        return 1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();