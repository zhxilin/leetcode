//1566. Detect Pattern of Length M Repeated K or More Times
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int count = 0;
        //第i位和第i + m必须相同才有可能重复k次,每成功比较一次,count计数+1
        //一共有k - 1次比较,如果重复k次,那么count最大为(k - 1) * m
        for (int i = 0; i + m < arr.size(); ++i) {            
            if (arr[i] != arr[i + m])
              count = 0;
            
            count += (arr[i] == arr[i + m]);
            
            if (count == (k - 1) * m)
                return true;
        }
        
        return false;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();