// ***
//
// In an array A of 0s and 1s, how many non-empty subarrays have sum S?
//
//
// Example 1:
//
// Input: A = [1,0,1,0,1], S = 2
// Output: 4
//
// Explanation:
// The 4 subarrays are bolded below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
//
//
// Note:
//
// A.length <= 30000
// 0 <= S <= A.length
// A[i] is either 0 or 1.
//
// ***
//
// This question is exactly the same as 560. Subarray Sum Equals K.

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> prefixSumToCount {{0 ,1}};

        int prefixSum = 0, numSubarrays = 0;
        for (int j = 0; j < A.size(); ++) {
            prefixSum += A[j];
            numSubarrays += prefixSumToCount[prefixSum - S];
            ++prefixSumToCount[prefixSum];
        }

        return numSubarrays;
    }
};
