// ***
//
// Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number
// of different integers in that subarray is exactly K.
//
// (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
//
// Return the number of good subarrays of A.
//
//
//
// Example 1:
//
// Input: A = [1,2,1,2,3], K = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2],
// [1,2,1,2]. Example 2:
//
// Input: A = [1,2,1,3,4], K = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
//
// ***

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        // num subarrays with exactly K distinct elements =
        // num subarrays with at most K distinct elements - num subarrays with at most K - 1 distinct elements
        return numSubarrayWithAtMostKDistinctElements(A, K) - numSubarrayWithAtMostKDistinctElements(A, K - 1);
    }

private:
    int numSubarrayWithAtMostKDistinctElements(vector<int>& A, int K) {
        unordered_map<int, int> window;

        int left = 0, right = 0;
        int count = 0;

        while (right < A.size()) {
            int num = A[right++];
            ++window[num];

            while (window.size() > K) {
                int num = A[left++];
                if (--window[num] == 0) {
                    window.erase(num);
                }
            }

            count += (right - left);
        }

        return count;
    }
};
