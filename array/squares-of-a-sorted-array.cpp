//977. Squares of a Sorted Array
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {              
        std::for_each(A.begin(), A.end(), [](int& x) { x *= x; });
        std::sort(A.begin(), A.end());
        return std::move(A);
    }
};