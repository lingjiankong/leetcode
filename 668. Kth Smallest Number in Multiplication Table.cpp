// ***
//
// Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).
// 
// Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.
// 
// 
// Example 1:
// 
// Input: m = 3, n = 3, k = 5
// Output: 3
// Explanation: The 5th smallest number is 3.
// 
// 
// Example 2:
// 
// Input: m = 2, n = 3, k = 6
// Output: 6
// Explanation: The 6th smallest number is 6.
//  
// 
// Constraints:
// 
// 1 <= m, n <= 3 * 10^4
// 1 <= k <= m * n
//
// ***

// Exactly same idea as 378. Kth Smallest Element in a Sorted Matrix
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n + 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Count the total number of elements in the multiplication table that are smaller than mid
            int count = 0;
            for (int i = 1; i <= m; ++i) {
                count += min(n, mid / i);
            }

            if (count == k) {
                right = mid;
            } else if (count < k) {
                left = mid + 1;
            } else if (count > k) {
                right = mid;
            }
        }

        return right;

    }
};
