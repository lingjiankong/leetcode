// ***
//
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum
// and return its sum.
//
// Example:
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
//
// ***

// The maximum sum of subarray that *ends at nums[i]* is the maximum of:
// 1. The maximum sum of subarray that ends at nums[i-1] plus nums[i], and
// 2. The value of nums[i] itself.
// O(n) space
int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];

    int maxSum = dp[0];

    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}

// O(1) space
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, curMaxSum = 0;

    for (int num : nums) {
        curMaxSum = max(curMaxSum + num, num);
        maxSum = max(maxSum, curMaxSum);
    }

    return maxSum;
}
