// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
//
//
// Example 1:
//
// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
//
//
// Example 2:
//
// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

// See 325. Maximum Size Subarray Sum Equals k. Almost the same.
// prefixSum here is the sum of 0 (-1) and 1 (1).
// Whenever prefixSum is 0, we know we have equal number of -1 and 1.
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;

        int maxLen = 0;
        int prefixSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += (nums[i] == 1) ? 1 : -1;

            if (prefixSum == 0) {
                maxLen = max(maxLen, i + 1);
            }

            if (hash.count(prefixSum)) {
                maxLen = max(maxLen, i - hash[prefixSum]);
            } else {
                // Add prefix sum to hash only if it doesn't exist
                // since we want the maximum length.
                hash[prefixSum] = i;
            }
        }

        return maxLen;
    }
};

