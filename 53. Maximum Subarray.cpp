int maxSubArray(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}
	
	int curSum = nums[0];
	int maxSum = nums[0];
	
	for (int i = 1; i < nums.size(); ++i)
	{
		curSum = max(curSum + nums[i], nums[i]);
		maxSum = max(curSum, maxSum);
	}
	
	return maxSum;
}
