//1832. Check if the Sentence Is Pangram
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> letters(26);
        int sum = 0;
        for (auto c : sentence) {
            if (!letters[c - 'a'])
                sum++;
            letters[c - 'a']++;
        }
        
        return sum == 26;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();