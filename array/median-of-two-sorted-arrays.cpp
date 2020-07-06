//4. Median of Two Sorted Arrays
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        //中位数代表左右两部分数量相同,若总数为偶数,则为左最大与右最小的均值;若为奇数,则为左最大
        int x = nums1.size(), y = nums2.size();
        int half = (x + y + 1) / 2; //切割后两部分的数量
        
        int low = 0, high = x;
        
        //二分法切割X,Y的数量则为half - X
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = half - partitionX;
            
            //分别求出两个数组切割后的左半部分最大值和右半部分最小值
            int maxLeftX = (0 == partitionX) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (x == partitionX) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (0 == partitionY) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (y == partitionY) ? INT_MAX : nums2[partitionY];
            
            //如果X的左最大不大于Y的右最小,且Y的左最大不大于X的右最小,
            //表示切割后{X左+Y左}的所有元素都不大于{X右+Y右},则这是一个目标切割
            //从目标切割中即可求出中位数
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if (0 == (x + y) % 2)
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                
                return max(maxLeftX, maxLeftY);
            } else if (maxLeftX > minRightY)
                high = partitionX - 1;
            else
                low = partitionX + 1;
        }
        
        return 0;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();