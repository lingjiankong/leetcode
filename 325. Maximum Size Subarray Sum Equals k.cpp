// ***
//
// Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one,
// return 0 instead.
//
// Note:
// The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.
//
// Example 1:
//
// Input: nums = [1, -1, 5, -2, 3], k = 3
// Output: 4
// Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
//
// Example 2:
//
// Input: nums = [-2, -1, 2, 1], k = 1
// Output: 2
// Explanation: The subarray [-1, 2] sums to 1 and is the longest.
//
// ***
//
// The idea of this question is similar to Two Sum.
//
// You keep an unordered_map which stores:
// Key: prefix sum
// Value: index corresponds to this prefix sum
//
// Suppose you are at current index with current prefixSum.
// To find the beginning index and end index of a subarray whose sum == k:
// Simply find if prefixSumToIndex[prefixSum-k] exists in the unordered_map
// If exists, then the beginning index of a subarray whose sum == k is just prefixSumToIndex[prefixSum-k] + 1
// (i.e. exculde everything from 0 to prefixSum-k inclusive), and the end index is current index.
// The length of this subarray is therefore index - prefixSumToIndex[prefixSum-k]
//
// If you read the code you would understand the idea.
//
// Compare this question with 209. Minimum Size Subarray Sum. In that question, we are looking for a minimum sliding
// window. In this question, we are looking for a maximum sliding window. They use different methods. Think about it
// yourself.

int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumToIndex;

    int prefixSum = 0;
    int maxLength = 0;

    for (int index = 0; index < nums.size(); ++index) {
        prefixSum += nums[index];

        if (prefixSum == k) {
            // Since we are trying to find the maxLength of subarray which sums to k,
            // if we see the prefixSum from 0 to current index is k, then
            // this must be the maxLength seen so far.
            maxLength = index + 1;
        } else if (prefixSumToIndex.count(prefixSum - k)) {
            // If prefixSum-k exists in the unordered_map, then we found a subarray which sums to k.
            // The index of this subarray starts from prefixSumToIndex[prefixSum-k] + 1 and end at current
            // index, so the length is just index - prefixSumToIndex[prefixSum-k]
            maxLength = max(maxLength, index - prefixSumToIndex[prefixSum - k]);
        }

        if (!prefixSumToIndex.count(prefixSum)) {
            // Only update prefixSumToIndex if prefixSum does not exist,
            // since you are trying to get maxLength of the subarray,
            // the smaller the index is, the larger the resulting length.
            prefixSumToIndex[prefixSum] = index;
        }
    }

    return maxLength;
}
