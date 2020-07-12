//1491. Average Salary Excluding the Minimum and Maximum Salary
class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = INT_MAX, maxSalary = INT_MIN;
        double sum = 0;
        for (int s : salary) {
            minSalary = min(minSalary, s);
            maxSalary = max(maxSalary, s);
            sum += s;
        }
        
        return (sum - minSalary - maxSalary) / (salary.size() - 2);
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();