class Solution {
public:
    int reverse(int x) {
        long reversed = 0;
        bool positive = true;

        if (x < 0) positive = false;

        while (x / 10 != 0) {
            // Guarantee a positive result from mod with abs()
            int digit = abs(x % 10);
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        int digit = abs(x % 10);

        // Check for overflow before operation
        if (positive && reversed * 10 + digit > INT_MAX) return 0;
        if (!positive && reversed * -10 - digit < INT_MIN) return 0;
        reversed = reversed * 10 + digit;

        // No overflow, return value
        return positive ? (int) reversed : (int) (reversed * -1);
    }
};