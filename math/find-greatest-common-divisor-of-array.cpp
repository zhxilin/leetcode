//1979. Find Greatest Common Divisor of Array
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int max = nums[n - 1];
        int min = nums[0];

        return gcd(min, max);
    }

    int gcd(int mn, int mx) {
        for (int i = mn; i >= 1; --i) {
            if (mn % i == 0 && mx % i == 0)
                return i;
        }

        return 1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();