//1535. Find the Winner of an Array Game
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
      
        int winIndex = 0, winCount = 0;
        
        for (int i = 1; i < n; ++i) {           
            if (arr[i] > arr[winIndex]) {                
                winIndex = i;
                winCount = 1;
            } else
                winCount++;
            
            if (winCount == k)
                return arr[winIndex];            
        }
        
        return arr[winIndex];
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();