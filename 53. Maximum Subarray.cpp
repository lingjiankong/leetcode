// ***
//
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// 
// Example:
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
//
// ***
//
// This is a DP problem.
// The maximum sum of subarray that ends at nums[i] depends on
// 1. The maximum sum of subarray that ends at nums[i-1] (i.e. last curSum) + nums[i], and 
// 2. The value of nums[i] itself.
// Therefore, curSum = max(curSum + nums[i], nums[i]).
//
int maxSubArray(vector<int>& nums)
{
	int maxSum = INT_MIN, curSum = 0;
	for (int num : nums)
	{
		curSum = max(curSum + num, num);
		maxSum = max(maxSum, curSum);
	}
	return maxSum;
}

// Same thing.
int maxSubArray(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}

	// The maximum sum of subarray that ends at nums[i]
	int curSum = nums[0];
	int maxSum = nums[0];
	
	for (int i = 1; i < nums.size(); ++i)
	{
		curSum = max(curSum + nums[i], nums[i]);
		maxSum = max(curSum, maxSum);
	}
	
	return maxSum;
}
