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

// labuladong sliding window template
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sumInWindow = 0;
        int left = 0, right = 0;
        int minLen = INT_MAX;

        while (right < nums.size()) {
            int num = nums[right++];
            sumInWindow += num;

            while (sumInWindow >= s) {
                minLen = min(right - left, minLen);
                num = nums[left++];
                sumInWindow -= num;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};

// left: leftmost element of the sliding window.
// right: rightmost element of the sliding window.
// sumInWindow: sum in the current sliding window.
//
// (Here, "push" means move one of the edges the sliding window to the right)
// Now, push the right bound of the sliding window and accumulate the sumInWindow.
// If sumInWindow is greater than s, then start pushing the left bound of the sliding window and see whether the
// remaining sumInWindow is still greater than s, and compare the length of the remaining sliding
// window with maxLength.
int minSubArrayLen(int s, vector<int>& nums) {
    int minLen = INT_MAX;
    int sumInWindow = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); ++right) {
        sumInWindow += nums[right];

        while (left <= right && sumInWindow >= s) {
            minLen = min(minLen, right - left + 1);
            sumInWindow -= nums[left++];
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}
