//287. Find the Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        //Floyd算法,检测环的存在
        int tortoise = nums[0];
        int hare = nums[0];
        
        //1.第一轮,龟兔赛跑,快指针追上满指针,交点则为兔子第二轮起跑位置
        do {
            tortoise = nums[tortoise];//走一步
            hare = nums[nums[hare]];//走两步
        } while (tortoise != hare);
                
        //2.第二轮,龟兔同速前进,相遇位置即为环的重合点        
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];//走一步
            hare = nums[hare];//走一步
        }
        
        return hare;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();