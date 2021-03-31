// ***
//
// Given an array of integers nums and an integer target.
//
// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is
// less or equal to target. Since the answer may be too large, return it modulo 10^9 + 7.
//
//
// Example 1:
//
// Input: nums = [3,5,6,7], target = 9
// Output: 4
// Explanation: There are 4 subsequences that satisfy the condition.
// [3] -> Min value + max value <= target (3 + 3 <= 9)
// [3,5] -> (3 + 5 <= 9)
// [3,5,6] -> (3 + 6 <= 9)
// [3,6] -> (3 + 6 <= 9)
//
//
// Example 2:
//
// Input: nums = [3,3,6,8], target = 10
// Output: 6
// Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
// [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
//
//
// Example 3:
//
// Input: nums = [2,3,3,4,6,7], target = 12
// Output: 61
// Explanation: There are 63 non-empty subsequences, two of them don't satisfy the condition ([6,7], [7]).
// Number of valid subsequences (63 - 2 = 61).
//
//
// Example 4:
//
// Input: nums = [5,2,4,1,7,6,8], target = 16
// Output: 127
// Explanation: All non-empty subset satisfy the condition (2^7 - 1) = 127
//
// ***
//
// Given an elements if we need to find out total number of sub sequences(without any condition) then it will be 2^n.
// [1, 2, 3] -> [], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]
//
// 先将数组排序（之所以可以排序求解，是因为并未要求子数组连续），left, right
// 分别指向数组首尾，如果满足首尾之和不超过target，
// 那么意味着从left + 1到right这些数字都存在两种选择（选和不选，left指向的数字必选），那么就存在2^(right−left)种选择
//
// Sort input A first. For each A[i], find out the maximum A[j] that A[i] + A[j] <= target.
// For each elements in the subarray A[i+1] ~ A[j], we can pick or not pick (you must pick A[i]).
// So there are 2 ^ (j - i) subsequences in total. So we can update res = (res + 2 ^ (j - i)) % mod.

class Solution {
public:
    int numSubseq(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        int res = 0, n = A.size(), mod = 1e9 + 7;
        int left = 0, right = n - 1, vector<int> pows(n, 1);
        for (int i = 1; i < n; ++i) {
            pows[i] = pows[i - 1] * 2 % mod;
        }
        while (left <= right) {
            if (A[left] + A[right] > target) {
                right--;
            } else {
                res = (res + pows[right - left++]) % mod;
            }
        }
        return res;
    }
};

