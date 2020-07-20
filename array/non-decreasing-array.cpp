//665. Non-decreasing Array
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        //arr[i] > arr[i+1]时，修改arr[i]为arr[i+1]，还是修改arr[i+1]为arr[i]，
        //取决于arr[i-1]与arr[i+1]的关系：
        //a.arr[i-1] < arr[i+1]时，令arr[i] = arr[i+1]，例如[2,5,3,4]，i=1，应令5改为3
        //b.arr[i-1] > arr[i+1]时，令arr[i+1] = arr[i]，例如[4,5,3,7], i=1，应令3改为5
        for (int i = 0; i < nums.size() - 1 && count <= 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                count++;
                
                if (i - 1 < 0 || nums[i - 1] <= nums[i + 1]) 
                    nums[i] = nums[i + 1];
                else 
                    nums[i + 1] = nums[i];
            }
        }
        
        return count <= 1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();