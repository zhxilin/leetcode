//912. Sort an Array
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::random_shuffle(nums.begin(), nums.end());
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        int pivot = partition(nums, low, high);

        quickSort(nums, low, pivot - 1);
        quickSort(nums, pivot + 1, high);
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];

        int i = low, j = high;

        while (i < j) {
            while (i < j && nums[j] >= pivot)
                j--;

            if (i < j) {
                nums[i] = nums[j];
                i++;
            }

            while (i < j && nums[i] <= pivot)
                i++;

            if (i < j) {
                nums[j] = nums[i];
                j--;
            }
        }

        nums[i] = pivot;

        return i;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();