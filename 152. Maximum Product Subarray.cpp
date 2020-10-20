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
    int currentMin = nums[0];
    int currentMax = nums[0];
    int maxProduct = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        // std::min and std::max takes two argument or an initializer list,
        // therefore if you want the min or max of three arguments you need to pass in a {}.
        int tempCurrentMin = min({currentMin * nums[i], currentMax * nums[i], nums[i]});
        int tempCurrentMax = max({currentMin * nums[i], currentMax * nums[i], nums[i]});

        currentMin = tempCurrentMin;
        currentMax = tempCurrentMax;

        maxProduct = max(maxProduct, currentMax);
    }

    return maxProduct;
}
