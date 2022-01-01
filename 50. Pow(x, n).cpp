// ***
//
// Implement pow(x, n), which calculates x raised to the power n (x^n).
//
// Example 1:
// Input: 2.00000, 10
// Output: 1024.00000
//
// Example 2:
// Input: 2.10000, 3
// Output: 9.26100
//
// Example 3:
// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
//
// ***

// Native for loop will TLE. Need optimization like this.
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            return 1 / power(x, -n);
        } else {
            return power(x, n);
        }
    }

private:
    double power(double x, int n) {
        if (n == 0) {
            return 1;
        }

        double half = power(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }
};
