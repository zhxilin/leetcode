//1287. Element Appearing More Than 25% In Sorted Array
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size();
        int targetCnt = size / 4;
        
        int cnt = 0, prev = arr[0];
        for (int i = 1; i < size; ++i) {
            if (prev == arr[i]) {
                cnt++;
                if (cnt > targetCnt) 
                    return arr[i];
            } else {
                cnt = 0;
                prev = arr[i];
            }
        }
        return arr[size - 1];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();