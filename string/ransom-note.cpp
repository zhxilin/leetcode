//383. Ransom Note
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vec(26);
        for (auto c : magazine) {
            vec[c - 'a']++;
        }
        
        for (auto c : ransomNote) {
            if (vec[c - 'a'] <= 0)
                return false;
            vec[c - 'a']--;
        }
        return true;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();