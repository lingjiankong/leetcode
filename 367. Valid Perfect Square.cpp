// ***
//
// Given a positive integer num, write a function which returns True if num is a perfect square else False.
// Note: Do not use any built-in library function such as sqrt.
//
// Example 1:
//
// Input: 16
// Output: true
//
// Example 2:
//
// Input: 14
// Output: false
//
// ***

// Brute force.
bool isPerfectSquare(int num) {
    for (int i = 1; i <= num / i; ++i) {
        if (i * i == num) {
            return true;
        }
    }

    return false;
}

// Find the largest x such that x * x <= num (find smallest x such that x * x > num and return right - 1),
// see if that number equals to num.
bool isPerfectSquare(long num) {
    if (num == 1) {
        return true;
    }

    long left = 1, right = num;

    while (left < right) {
        long mid = left + (right - left) / 2;
        if (mid * mid == num) {
            left = mid + 1;
        } else if (mid * mid < num) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return (right - 1) * (right - 1) == num ? true : false;
}

// Similar idea.
bool isPerfectSquare(long num) {
    if (num == 1) {
        return true;
    }

    long left = 1, right = num;

    while (left < right) {
        long mid = left + (right - left) / 2;
        if (mid * mid == num) {
            return true;
        } else if (mid * mid < num) {
            left = mid + 1;
        } else if (mid * mid > num) {
            right = mid;
        }
    }

    return false;
}
