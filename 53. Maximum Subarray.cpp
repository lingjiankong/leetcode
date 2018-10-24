// This is a DP problem.
// The maximum sum of subarray that ends at nums[i] depends on
// 1. The maximum sum of subarray that ends at nums[i-1] (i.e. last curSum), and 
// 2. The value of nums[i] itself.
// Therefore, curSum = max(curSum + nums[i], nums[i]).
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
