//1175. Prime Arrangements
class Solution {
public:
    int numPrimeArrangements(int n) {
        int p = 0;
        for (int i = 2; i <= n; ++i) {
            if (isPrimie(i))
                p++;
        }
        
        int a = factorial(p) % mod;
        int b = factorial(n - p) % mod;
        return ((long long) a * b) % mod;
    }

private:
    bool isPrimie(int n) {
        if (1 == n) return false;
        
        for (int i = 2; i < n; ++i) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    
    int factorial(int n) {        
        int result = 1;
        for (int i = 2; i <= n; ++i) {
            result %= mod;
            result = ((long long)result * i) % mod;
        }
        return result;
    }
    
    int mod = 1e9 + 7;
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();