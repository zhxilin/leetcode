//8. String to Integer (atoi)
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        for (i = 0; s[i] == ' '; ++i);

        int sign = 1;

        if (s[i] == '+')
            i++;
        else if (s[i] == '-') {
            sign = -1;
            i++;
        }

        long long result = 0;

        for (; i < n; ++i) {
            if (!isdigit(s[i]))
                break;

            result = result * 10 + (s[i] - '0');

            if (result > INT_MAX)
                return sign == 1 ? INT_MAX : INT_MIN;
        }

        return sign * result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();