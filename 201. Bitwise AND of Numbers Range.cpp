// ***
//
// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
// 
// Example 1:
// 
// Input: [5,7]
// Output: 4
//
// Example 2:
// 
// Input: [0,1]
// Output: 0
//
// ***
//
// The result of a range bitwise is the common "left header" of m and n.
//
// Given [5, 7], we have 5, 6, 7's binary representations
// 101    110    111
// Bitwise AND the above give binary 100
//
// For example, given [26, 30], we have 26, 27, 28, 29, 30's binary representations
// 11010    11011   11100   11101   11110
// Bitwise AND the above gives binary 11000
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return (m << i);
    }
};
