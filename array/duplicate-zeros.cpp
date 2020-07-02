//1089. Duplicate Zeros
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        //统计0的个数, i最终值为原数组前i个有效数值,剩余数值会被覆盖
        int cnt = 0, i = 0;
        for (; i < arr.size() - cnt; ++i) {
            cnt += arr[i] == 0;
        }
        
        int j = arr.size() - 1;
        
        //边缘值为0的,没法复制
        if (i > arr.size() - cnt) {
            arr[j--] = 0;
            i = arr.size() - cnt;
        }
        
        //从后往前更新
        while (i--) {
            arr[j--] = arr[i];
            if (arr[i] == 0)
                arr[j--] = arr[i];
        }
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();