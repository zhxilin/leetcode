//1629. Slowest Key
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> timespans(26);
        timespans[keysPressed[0] - 'a'] = releaseTimes[0];
        
        int prev = 0;
        for (int i = 1; i < releaseTimes.size(); ++i) {
            prev = releaseTimes[i] - releaseTimes[i - 1];
            timespans[keysPressed[i] - 'a'] = max(timespans[keysPressed[i] - 'a'], prev);
        }
        
        int maxTimes = 0;
        char result;
        for(int i = 0; i < 26; ++i)
            if (maxTimes <= timespans[i]){
                result = 'a' + i;
                maxTimes = timespans[i];
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