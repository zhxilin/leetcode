//1437. Check If All 1's Are at Least Length K Places Away
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -k - 1;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums[i]) {
                if (i - last - 1 < k) return false;
                last = i;
            }
        }
        
        return true;
    }
};

static auto _= []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();