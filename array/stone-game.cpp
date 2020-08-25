//877. Stone Game
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        //Alex先行，总能逼迫Lee只取偶数位或奇数位，举例：
        //0 1 2 3 4 5
        //^
        //Alex先行，必在0和5中选一个，Alex永远有办法迫使对方每一步只能选奇数位或偶数位
        //假设Alex选0，Lee只能在1和5中选，总有办法逼迫对方选奇数位
        //  若Lee选1，Alex选2，Lee又只能在3和5中选（又是奇数）
        //  若Lee选5，Alex选4，Lee又只能在1和3中选（又是奇数）
        //同理，假设Alex选5，Lee只能在0和4中选，总有办法逼迫对方选偶数位
        //这样Alex可以保证永远只选奇数或永远只选偶数，而因为没有平局，奇数位之和偶数位之和总有大小之分，
        //换言之，先行者一定总能得到较大的和，即先行必赢
        
        return true;
    }
};