// ***
//
// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of
// which the sum ≥ s. If there isn't one, return 0 instead.
//
// Example:
//
// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
//
// ***
//
// This problem is very intuitive once you understand it. The idea is to keep a sliding window.
//
// The initial left bound of the sliding window is 0.
// The right bound of the sliding window is index i.
//
// Now, push the right bound of the sliding window and accumulate the sum.
// If the sum is greater than s, then start pushing the left bound of the sliding window and see whether the
// remaining sum inside the sliding window is still greater than s, and compare the length of the remaining sliding
// window with maxLength.

int minSubArrayLen(int s, vector<int>& nums) {
    // Minimum length of the subarray which sum >= s.
    int minLength = INT_MAX;

    // Sum in the current sliding window.
    int sum = 0;

    // Left bound of the sliding window.
    int left = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];

        while (left <= i && sum >= s) {
            minLength = min(minLength, i - left + 1);
            sum -= nums[left++];
        }
    }

    return minLength == INT_MAX ? 0 : minLength;
}
