// ***
//
// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has
// the largest product.
//
// Example 1:
//
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:
//
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
//
// ***
//
// This a dynamic programming problem.
//
// See also 53. Maximum Subarray.
//
// The maximum product of subarray ending in nums[i] depends on both its own sign and
// the max *and* min product of the subarray ending in nums[i-1], and the value of nums[i] itself.
//
// In other word, max/min product of subarray ending in the current number is either the current number itself
// or the max/min of the subarray ending in previous number times the current number.
//
// Therefore we need to keep track of min and max products of the subarray ending in nums[i-1].

int maxProduct(vector<int>& nums) {
    int curMin = nums[0];
    int curMax = nums[0];
    int maxProduct = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        int tempCurMin = min({curMin * nums[i], curMax * nums[i], nums[i]});
        int tempCurMax = max({curMin * nums[i], curMax * nums[i], nums[i]});

        curMin = tempCurMin;
        curMax = tempCurMax;

        maxProduct = max(maxProduct, curMax);
    }

    return maxProduct;
}
