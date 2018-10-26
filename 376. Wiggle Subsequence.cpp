// This is a good dynamic programming problem.
int wiggleMaxLength(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}

	// up[i] is the length of a longest wiggle subsequence that ends at nums[i] 
	// with a positive difference between its last two numbers.
	// At i=0, there is only one number and we can use it as a subsequence, i.e up[0]=down[0]=1
	int up = 1;

	// down[i] is the length of a longest wiggle subsequence that ends at nums[i]
	// with a negative difference between its last two numbers.
	int down = 1;

	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] > nums[i-1])
		{
			up = down + 1;
		}
		else if (nums[i] < nums[i-1])
		{
			down = up + 1;
		}
		// else if nums[i] == nums[i-1], then up and down are not updated.
	}

	return max(up, down);
}
