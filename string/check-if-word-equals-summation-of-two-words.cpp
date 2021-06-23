//1880. Check if Word Equals Summation of Two Words
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return getNumericalValue(firstWord) + getNumericalValue(secondWord) == getNumericalValue(targetWord);
    }

private:
    int getNumericalValue(string s) {
        int n = s.size() - 1;
        int value = 0;
        int step = 1;
        for (int i = n; i >= 0; --i) {
            value += (s[i] - 'a') * step;
            step *= 10;
        }
        return value;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();