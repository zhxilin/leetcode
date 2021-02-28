//1025. Divisor Game
class Solution {
public:
    bool divisorGame(int N) {
        //dp[i]表示数值为i时是否能赢
        vector<bool> dp(N + 1);
        //base case
        dp[0] = true;
        dp[1] = false;
        
        for (int i = 2; i <= N; ++i) {
            for (int k = 2; k <= i; ++k) {
                int j = i / k; //无法整除跳过,找到可以被i整除的j
                if (j * k != i) 
                    continue;
                
                //只有上一步无法赢时,这一步才能赢,因为总有办法走出当前这一步:
                //即如果i为奇数,存在j使得i-j为偶数; 如果i为偶数,存在j=1使得i-j为奇数
                if (!dp[i - j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[N];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();