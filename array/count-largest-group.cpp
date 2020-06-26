//1399. Count Largest Group
class Solution {
public:
    int countLargestGroup(int n) {
        //最大的和由9999组成，即36，故定义一个数组大小为37
        vector<int> cnts(37, 0);
        int maxSize = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            int s = sum(i);
            cnts[s]++;
            maxSize = max(maxSize, cnts[s]);
        }
        
        int result = 0;
        for (int cnt : cnts) {
            if (cnt == maxSize)
                result++;
        }
        
        return result;
    }

private:
    int sum(int num) {
        int s = 0;
        
        while (num) {
            s += num % 10;
            num /= 10;
        }
        
        return s;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();