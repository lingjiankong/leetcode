// ***
//
// Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
//
// Return the length of the longest (contiguous) subarray that contains only 1s.
//
//
// Example 1:
//
// Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
// Output: 6
// Explanation:
// [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
//
//
// Example 2:
//
// Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
// Output: 10
// Explanation:
// [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
//
// ***
//
// Can be rephrased as: find the longest contiguous subarray that contains at most K 0s.

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        vector<int> window(2, 0);

        int left = 0, right = 0;
        int maxLen = 0;

        while (right < A.size()) {
            int num = A[right++];
            ++window[num];

            while (window[0] > K) {
                int num = A[left++];
                --window[num];
            }

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};
