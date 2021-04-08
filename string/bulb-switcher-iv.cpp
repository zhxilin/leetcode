//1529. Bulb Switcher IV
class Solution {
public:
    int minFlips(string target) {
        //初始状态全为0,从左到右第0位开始,每遇到和目标不一样的,则翻转从该位置到结束
        //没必要用string记录当前所有灯的状态,只需要记当前位置的灯状态即可,因为后续灯的状态与当前位置是一样的
        int result = 0, cur = 0;
        for (const auto& c : target) {
            if ((c - '0') != cur) {
                cur = !cur;
                result++;
            }
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