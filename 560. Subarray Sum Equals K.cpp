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

int subarraySum(vector<int>& nums, int k) {
    int count = 0, cumulativeSum = 0;

    // Key: cumulativeSum that you have seen before
    // Value: How many times you've seen that cumulativeSum
    // Initially, we have seen cumulativeSum = 0 for 1 time.
    unordered_map<int, int> cumulativeSumToCount{{0, 1}};

    for (int i = 0; i < nums.size(); ++i) {
        cumulativeSum += nums[i];

        // If seen[cumulativeSum - k] exists, this means we've seen our cumulative sum at some point before (let's say
        // at index j, for example) to be (cumulativeSum - k). This means that there exists a subarray from (j + 1) to i
        // that adds up to k.
        count += cumulativeSumToCount[cumulativeSum - k];

        ++cumulativeSumToCount[cumulativeSum];
    }

    return count;
}
