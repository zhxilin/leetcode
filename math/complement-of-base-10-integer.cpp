//1009. Complement of Base 10 Integer
class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) 
            return 1;
        
        unsigned int bits = floor(log2(N)) + 1;
        return ((unsigned int)(1 << bits) - 1) ^ N;
    }
};