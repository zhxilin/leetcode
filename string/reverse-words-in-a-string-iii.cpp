//557. Reverse Words in a String III
class Solution {
public:
    string reverseWords(string s) {
        //为了让最后一个单词可以在迭代中直接翻转,在其后补充一个分隔符‘ ’,处理完成后再去掉分隔符即可
        s.push_back(' ');
        int l = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + l, s.begin() + i);
                l = i + 1;
            }
        }
        s.pop_back();
        return s;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();