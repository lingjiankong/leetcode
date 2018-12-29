// ***
//
// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers. You may assume that each input would have exactly one solution.
// 
// Example:
// 
// Given array nums = [-1, 2, 1, -4], and target = 1.
// 
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
// ***
//
// See also 15. 3Sum.
// For this question, we just need to return an int which is the closest sum of three target in nums.
// There's no need to remove duplicate, so the code is not as complex.
int threeSumClosest(vector<int>& nums, int target)
{
	int closest = nums[0] + nums[1] + nums[2];
	int diff = abs(closest - target);

	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size() - 2; ++i)
	{
		int left = i + 1, right = nums.size() - 1;
		while (left < right)
		{
			int sum = nums[i] + nums[left] + nums[right];
			int newDiff = abs(sum - target);
			if (newDiff < diff)
			{
				diff = newDiff;
				closest = sum;
			}

			if (sum < target)
			{
				++left;
			}
			else
			{
				--right;
			}
		}
	}

	return closest;
}
