// ***
//
// You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k
// coins.
//
// Given n, find the total number of full staircase rows that can be formed.
//
// n is a non-negative integer and fits within the range of a 32-bit signed integer.
//
// Example 1:
//
// n = 5
//
// The coins can form the following rows:
// ¤
// ¤ ¤
// ¤ ¤
//
// Because the 3rd row is incomplete, we return 2.
// Example 2:
//
// n = 8
//
// The coins can form the following rows:
// ¤
// ¤ ¤
// ¤ ¤ ¤
// ¤ ¤
//
// Because the 4th row is incomplete, we return 3.
//
// ***

// Brute force, O(n).
class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 1) {
            return n;
        }

        int levels = 1, remainingCoins = n - 1;
        while (remainingCoins >= levels + 1) {
            ++levels;
            remainingCoins -= levels;
        }

        return levels;
    }
};

// Binary search, O(nlogn).
class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 1) {
            return n;
        }

        long left = 1, right = n;
        while (left < right) {
            long mid = left + (right - left) / 2;

            // To be able to build stairs with n level, we need at least n(n+1)/2 coins.
            if (mid * (mid + 1) / 2 <= n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // Returns the last number that is less than target n
        return right - 1;
    }
};
