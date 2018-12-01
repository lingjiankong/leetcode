// ***
//
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// 
// Example:
// 
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// 
// Note: You can assume that you can always reach the last index.
//
// ***
//
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
