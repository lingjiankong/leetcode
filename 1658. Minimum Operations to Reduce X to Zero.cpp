// ***
//
// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the
// rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future
// operations.
//
// Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.
//
//
// Example 1:
//
// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
//
//
// Example 2:
//
// Input: nums = [5,6,7,8,9], x = 4
// Output: -1
//
//
// Example 3:
//
// Input: nums = [3,2,20,1,1,3], x = 10
// Output: 5
// Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in
// total) to reduce x to zero.
//
// ***
//
// Note: all numbers are positive.
//
// Problem translation: Find the longest subarray of length len(sums) - k which sum is sum(nums) - x

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;

        if (target < 0) {
            return -1;
        }

        if (target == 0) {
            return nums.size();
        }

        int windowSum = 0, maxLen = 0;
        int left = 0, right = 0;

        while (right < nums.size()) {
            int num = nums[right++];
            windowSum += num;

            while (windowSum > target) {
                int num = nums[left++];
                windowSum -= num;
            }

            if (windowSum == target) {
                maxLen = max(maxLen, right - left);
            }
        }

        return maxLen == 0 ? -1 : nums.size() - maxLen;
    }
};

