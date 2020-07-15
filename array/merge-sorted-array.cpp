//88. Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, position = m + n - 1;
        while (j >= 0) {
            nums1[position--] = i >= 0 && nums1[i] > nums2[j] ? 
                nums1[i--] : 
                nums2[j--];
        }
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();