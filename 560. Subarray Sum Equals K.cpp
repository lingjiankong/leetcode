// ***
//
// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum
// equals to k.
//
// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2
//
// Note:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
//
// ***
//
// This is a very classic question. You should understand how it works.
// See https://www.youtube.com/watch?v=GZOBCV-soyE for intuition.
//
// This question is exactly the same as 930. Binary Subarrays With Sum.
//
// X X [i X X X X j] X X X X
// We have two pointers i and j that traverse through the array,
// we want to find all i, j such that the subarray [i, j] (inclusive) sums to k.
// By constructing an array of prefix sums, we want to know all i, j such that prefixSum[j] - prefixSum[i - 1] = k.
// That is, for every j, how many i such that prefixSum[i - 1] = prefixSum[j] - k?
// To count this, we can simply use a hash table of (prefix sum) : (count of occurances we've seen the prefix sum).

int subarraySum(vector<int>& nums, int k) {
    // Key: prefixSum that you have seen before
    // Value: How many times you've seen that prefixSum
    // Initially, we have seen prefixSum = 0 for 1 time (this is needed to capture the case when prefixSum - k = 0)
    unordered_map<int, int> prefixSumToCount{{0, 1}};

    int prefixSum = 0, numSubarrays = 0;
    for (int j = 0; j < nums.size(); ++j) {
        prefixSum += nums[j];

        // If prefixSumToCount[prefixSum - k] exists, this means we've seen our prefixSum - k at some point before (let's say
        // at index i - 1, for example, which means that subarray [i, j] (inclusive) adds up to k).
        numSubarrays += prefixSumToCount[prefixSum - k];

        ++prefixSumToCount[prefixSum];
    }

    return numSubarrays;
}
