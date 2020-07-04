//1275. Find Winner on a Tic Tac Toe Game
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        //不同质数的乘积唯一
        static int primes[3][3] = {{2, 3, 5}, {7, 11, 13}, {17, 19, 23}};
        static int wins[8] = {2 * 3 * 5, 7 * 11 * 13, 17 * 19 * 23, //行赢
                              2 * 7 * 17, 3 * 11 * 19, 5 * 13 * 23, //列赢
                              2 * 11 * 23, 5 * 11 * 17}; //对角赢
        
        int a = 1, b = 1;
        
        //将每一步做乘积,最终结果若能整除赢集合中的数,则代表他赢了
        for (int i = 0; i < moves.size(); ++i) {
            int r = moves[i][0];
            int c = moves[i][1];
            
            int v = primes[r][c];
            
            if (0 == i % 2)
                a *= v;
            else
                b *= v;
        }
        
        for (int win : wins) {
            if (0 == a % win) return "A";
            if (0 == b % win) return "B";
        }
        
        return 9 == moves.size() ? "Draw" : "Pending";
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();