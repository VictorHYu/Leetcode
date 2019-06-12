class Solution {
public:
    int myAtoi(string str) {
        int start = 0;
        bool positive = true;

        // trim whitespace
        while (start < str.length()) {
            if (str[start] == ' ') start++;
            else break;
        }

        // all whitespace
        if (start == str.length()) return 0;

        // check negative and positive
        if (str[start] == '-') {
            positive = false;
            start++;
        } else if (str[start] == '+') {
            start++;
        }

        // invalid char
        if (start == str.length() || str[start] > '9' || str[start] < '0') return 0;

        // trim zeroes
        while (start < str.length()) {
            if (str[start] == '0') start++;
            else break;
        }

        int digits = 0;
        long num = 0;

        for (int i = start; i < str.length(); ++i) {
            if (str[i] <= '9'  && str[i] >= '0') {
                num = num * 10 + (str[i] - '0');
                digits++;
            } else {
                break;
            }

            // check overflow on 10 digits
            if (positive && num >= INT_MAX) {
                return INT_MAX;
            }
            if (!positive && num * -1 <= INT_MIN) {
                return INT_MIN;
            }

            // check up to 11 digits
            if (digits == 11) {
                return positive ? INT_MAX : INT_MIN;
            }
        }

        if (!positive) num *= -1;

        return (int) num;
    }
};