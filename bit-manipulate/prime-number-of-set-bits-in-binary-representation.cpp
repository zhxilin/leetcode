//762. Prime Number of Set Bits in Binary Representation
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        const unordered_set<int> primes {2, 3, 5, 7, 11, 13, 17, 19};
        
        int result = 0;
        for (int i = L; i <= R; ++i) {
            int cnt = countSetBits(i);
            result += primes.count(cnt);
        }
        
        return result;
    }

private:
    int countSetBits(int n) {
        int cnt = 0;
        while (n) {
            cnt += n % 2;
            n /= 2;
        }
        return cnt;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();