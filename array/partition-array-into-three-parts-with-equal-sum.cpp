//1013. Partition Array Into Three Parts With Equal Sum
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0) return false;
        
        int partSum = 0, counts = 0, avr = sum / 3;
        for (int num : A) {
            if (counts >= 3)
                break;
            partSum += num;
            if (partSum == avr) {
                counts++;
                partSum = 0;
            }
        }
        
        return counts == 3;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();