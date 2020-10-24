// ***
//
// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
//
// Example 1:
//
// Input: 121
// Output: true
//
// Example 2:
//
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a
// palindrome.
//
// Example 3:
//
// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//
// ***
//
// The idea is to reverse the integer and compare the reversed with the original.
//
// To visualize the while loop:
//
// Example:
// 36425
//
// reversed = 0 (initialize);
//
// reversed = reversed * 10 + x % 10;
// reversed = 0 * 10 + 36425 % 10
// reversed = 5
// x /= 10;
// x = 36425 / 10 = 3642
//
// reversed = reversed * 10 + x % 10;
// reversed = 5 * 10 + 3642 % 10
// reversed = 52
// x /= 10;
// x = 3642 / 10 = 364
//
// reversed = reversed * 10 + x % 10;
// reversed = 52 * 10 + 364 % 10
// reversed = 524
// x /= 10;
// x = 364 / 10 = 36
// ...
//
// reversed will eventually be 52463

bool isPalindrome(int x) {
    // Negative number cannot be a palindrome.
    if (x < 0) {
        return false;
    }

    int original = x;
    int reversed = 0;

    while (x != 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return reversed == original;
}
