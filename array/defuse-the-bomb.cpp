//1652. Defuse the Bomb
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n);
        
        if (k > 0) {
            int ksum = 0;
            for (int i = 0; i < k; ++i) {
                ksum += code[i];
            }
            
            for (int i = 0; i < n; ++i) {
                ksum -= code[i];
                ksum += code[(i + k) % n];
                result[i] = ksum;
            }
        } else if (k < 0) {
            int ksum = 0;
            for (int i = n - 1; i >= n + k; --i) {
                ksum += code[i];
            }
            
            for (int i = n - 1; i >= 0; --i) {
                ksum -= code[i];
                ksum += code[(n + i + k) % n];
                result[i] = ksum;
            }            
        }
        
        return result;
    }
};


static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;  
};