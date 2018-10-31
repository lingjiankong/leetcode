// Note that the problem guarantees that that we are can always jump to the last index.
// Therefore no need to check if we can jump to current index.
int jump(vector<int>& nums)
{
	int totalJump = 0;

	// The ending index of current window.
	// You can jump to every index in this window in the same number of step from previous window.
	int currentEnd = 0;

	// The farthest index we can jump from current window,
	// this will be used to update currentEnd when we've reached the end of current window.
	int currentMaxReach = 0;

	for (int i = 0; i < nums.size()-1; ++i)
	{
		currentMaxReach = max(currentMaxReach, i + nums[i]);

		// If we've reached the end of current window, this will trigger another jump from current window.
		// Why we have ;i<nums.size()-1;? Because if we had ;i<nums.size();, we were including the last index,
		// then another jump is triggered at last index, and our totalJump will be 1 greater than what it should have been
		if (i == currentEnd)
		{
			++totalJump;
			currentEnd = currentMaxReach;
		}
	}

	return totalJump;
}
