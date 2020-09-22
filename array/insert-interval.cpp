//57. Insert Interval
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        
        for (const vector<int>& interval : intervals) {
            //1.newInterval在其他interval后方
            if (interval[1] < newInterval[0])
                result.push_back(interval);            
            //2.newInterval在其他interval前方
            else if (interval[0] > newInterval[1]) {
                result.push_back(newInterval);
                newInterval = interval;
            }
            //3.newInterval与其他interval有交叉
            else if (interval[0] <= newInterval[1] || interval[1] >= newInterval[0]) {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        result.push_back(newInterval);
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();