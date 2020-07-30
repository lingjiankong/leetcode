// ***
//
// Implement int sqrt(int x).
//
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is
// returned.
//
// Example 1:
//
// Input: 4
// Output: 2
//
// Example 2:
//
// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
//
// ***
//
// Find last mid such that mid * mid <= x (target).
// So we use std::upper_bound() to find the first mid such that mid * mid > x
// Then index right - 1 is the last mid such that mid * mid <= x

int mySqrt(int x) {
    if (x <= 1) {
        return x;
    }

    int left = 0, right = x;
    while (left < right) {
        int mid = left + (right - left) / 2;

        // Theoretically you can also write if (mid * mid <= x),
        // but mid * mid will overflow, so you write if (mid <= x / mid)
        if (mid <= x / mid) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    // right is the first element that is greater than target;
    // right - 1 is the last element that is not greater than target;
    return right - 1;
}
