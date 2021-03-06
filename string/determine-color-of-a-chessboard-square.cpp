//1812. Determine Color of a Chessboard Square
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a';
        int y = coordinates[1] - '0';
        
        if (x % 2 == 0)
            return y % 2 == 0;
        
        return y % 2 != 0;
    }
};