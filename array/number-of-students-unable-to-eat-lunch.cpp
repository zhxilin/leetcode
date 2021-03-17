//1700. Number of Students Unable to Eat Lunch
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cir = 0, squ = 0;
        
        for (int s : students) {
            if (s)
                cir++;
            else
                squ++;
        }
        
        for (int s : sandwiches) {
            if (s && cir)
                cir--;
            else if (!s && squ)
                squ--;
            else
                break;
        }
        
        if (cir)
            return cir;
        
        if (squ)
            return squ;
        
        return 0;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();