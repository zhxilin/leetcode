//1185. Day of the Week
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        //Tomohiko Sakamoto算法
        static string daysOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        static int daysByMonthMod7[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        year -= month < 3;
        return daysOfWeek[(year + year / 4 - year / 100 + year / 400 + daysByMonthMod7[month - 1] + day) % 7];
    }
};