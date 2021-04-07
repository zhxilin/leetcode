//885. Spiral Matrix III
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {  
        int cnt = 0, total = R * C, step = 1, dir = 0;
        vector<vector<int>> result;  
        
        //从起始点开始,每个方向的步长有如下规律:1,1,2,2,3,3,4,4,...
        //向东1步,向南1步,向西2步,向北2步,
        //再向东3步,向南3步,向西4步,向北4步...
        
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        
        int pr = r0, pc = c0;
        result.push_back({pr, pc});       
        
        while (result.size() < total) {
            for (int i = 1; i <= step; ++i) {
                pr += dr[dir % 4], pc += dc[dir % 4];
                if (pr >= 0 && pr < R && pc >= 0 && pc < C)
                    result.push_back({pr, pc});
            }
            
            //更新步长
            if (dir & 1)
                step++;
            
            //每前进一步改变一次方向
            dir++;          
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