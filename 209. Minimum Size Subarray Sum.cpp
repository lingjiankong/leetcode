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
// left: leftmost element of the sliding window.
// right: rightmost element of the slidint window.
// sum: sum in the current sliding window.
//
// (Here, "push" means move one of the edges the sliding window to the right)
// Now, push the right bound of the sliding window and accumulate the sum.
// If the sum is greater than s, then start pushing the left bound of the sliding window and see whether the
// remaining sum inside the sliding window is still greater than s, and compare the length of the remaining sliding
// window with maxLength.

int minSubArrayLen(int s, vector<int>& nums) {
    int minLength = INT_MAX;
    int sum = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); ++right) {
        sum += nums[right];

        while (left <= right && sum >= s) {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left++];
        }
    }

    return minLength == INT_MAX ? 0 : minLength;
}
