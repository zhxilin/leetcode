//1450. Number of Students Doing Homework at a Given Time
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        if (startTime.size() != endTime.size()) return 0;
        
        int num = 0;
        for (int i = 0; i < startTime.size(); ++i) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                num++;
        }
        return num;
    }
};