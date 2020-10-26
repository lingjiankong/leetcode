// ***
//
// Given an integer, write a function to determine if it is a power of two.
//
// Example 1:
// Input: 1
// Output: true
// Explanation: 2^0 = 1
//
// Example 2:
// Input: 16
// Output: true
// Explanation: 2^4 = 16
//
// Example 3:
// Input: 218
// Output: false
//
// ***
//
// In binary representation, all power of two must only has one 1.
//
// 1    2     4     8     16 　　....
// 1    10    100   1000  10000　....

// Faster method.
bool isPowerOfTwo(int n) {

    // Count how many times "1" appears in the binary representation of n. 
    int count = 0;

    while (n > 0) {
        count += (n & 1);
        n >>= 1;
    }

    return count == 1;
}

// Slower method. Same ideas as 326. Power of Three, and 342. Power of Four.
bool isPowerOfFour(int num) {
    while ((num > 0) && (num % 2 == 0)) {
        num /= 2;
    }

    return num == 1;
}

