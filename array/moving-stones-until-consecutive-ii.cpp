//1040. Moving Stones Until Consecutive II
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        
        //最大次数:移动开头或末尾到中间任意每一个未占据的位置
        //移动开头,则总次数为s[n - 1] - s[1] - n + 1
        //移动末尾,则总次数为s[n - 2] - s[0] - n + 1
        int maxMoves = max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2);
        
        //最小次数:滑动窗口大小,使得窗口可以容纳所有石头
        int i = 0, j = 0, minMoves = n;
        
        while (j < n) {
            //窗口大小,最大的窗口大小为n
            int windowSize = stones[j] - stones[i] + 1;
            //已容纳的石头数
            int storeStones = j - i + 1;
            
            if (windowSize > n) {
                i++;
                continue;
            }
            
            //将不在窗口中的石头移进窗口中,那么窗口中的空位数量n - storeStones就是需要移动的步数
            //边缘情况,当窗口大小和窗口中已容纳的石头数为n - 1,即仅剩一个石头未移动,移动的步数至少为2
            //例如:[1,2,3,4],10
            //此时10不可直接移到4旁边,因为不符合题目要求->移动后不可再为边缘石头
            //因此应该移动2步:1移到位置6,10移到位置5,最终为[2,3,4,10,1]
            if (windowSize == n - 1 && storeStones == n - 1)
                minMoves = min(minMoves, 2);
            else
                minMoves = min(minMoves, n - storeStones);
            
            j++;
        }
        
        return {minMoves, maxMoves};
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();