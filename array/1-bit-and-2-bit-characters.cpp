//717. 1-bit and 2-bit Characters
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int size = bits.size();
        int i = 0;
        while (i < size) {
            if (0 == bits[i]) {
                if (i + 1 >= size)
                    break;
                i++;
            } else {
                if (i + 2 >= size)
                    break;
                i += 2;
            }
        }
        
        return size - i == 1;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;  
};