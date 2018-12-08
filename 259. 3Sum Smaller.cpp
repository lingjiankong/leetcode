// ***
//
// Given an array of n integers nums and a target, find the number of index triplets i, j, k with
// 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
// 
// Example:
// 
// Input: nums = [-2,0,1,3], and target = 2
// Output: 2
// Explanation: Because there are two triplets which sums are less than 2:
//              [-2,0,1]
//              [-2,0,3]
// ***
//
int threeSumSmaller(vector<int>& nums, int target)
{
	int total = 0, n = nums.size();

	sort(nums.begin(), nums.end());

	for (int i = 0; i < n - 2; ++i)
	{
		int left = i + 1, right = n - 1;
		while (left < right)
		{
			// Explanation of total += right - left:
			// As we have sort the elements in nums array, then for a triple i, left, right that matches requirement (sum < target),
			// any elements that smaller than nums[right] and larger than nums[left] can still match it, as the sum can only go smaller.
			// How many alternatives/elements that are smaller than nums[right] and larger than nums[left]? right - left.
			//
			// Here if nums[i] + nums[left] + nums[right] < target, then we will increment left (++left) and go to the next while loop.
			// We must also take into account valid answers nums[i] + nums[left] + nums[right-1], nums[i] + nums[left] + nums[right - 2] ...
			// There are total of right - left such combinations -> therefore total += right - left.
			if (nums[i] + nums[left] + nums[right] < target)
			{
				total += right - left;
				++left;
			}
			else
			{
				--right;
			}
		}
	}

	return total;
}

// Brute force, clear but TLE.
int threeSumSmaller(vector<int>& nums, int target)
{
	int total = 0;

	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size() - 2; ++i)
	{
		for (int j = i + 1; j < nums.size() - 1; ++j)
		{
			for (int k = j + 1; k < nums.size(); ++k)
			{
				if (nums[i] + nums[j] + nums[k] < target)
				{
					++total;
				}
			}
		}
	}

	return total;
}
