// The idea of the question is to put positive elements in their corresponding spots.
// We don't care about elements that are non positive and elements that are larger than nums.size(),
// because they can't be the first missing postive.
//
// Example:
//
// Given (after sorted) [-99, -4, 0, 1, 2, 4, 5, 6, 100, 230]
//
// Index:
// [0 1 2 3 4 5 6 7]
// At position 2, we should get 3, but we didn't, therefore, first missing positive is 3
// [1 2 ? 4 5 6 ? ?]

int firstMissingPositive(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 1;
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		// If 0 < nums[i] < nums.size(), we want to put nums[i] at nums[nums[i]-1].
		//
		// After swap(nums[i], nums[nums[i]-1]), nums[nums[i]-1] has the correct value (i.e. nums[i]),
		// but the new nums[i] might still be incorrect,
		// so we must have WHILE loop here instead of an IF statement.
		//
		// For example, if we have [3, 1, 4, -1], when i = 0, num[0] = 3,
		// we swap nums[0] with nums[3-1] and get [4, 1, 3, -1].
		// Now, nums[2] = 3, which is correct. However, nums[0] = 4,
		// if we were using an if loop, nums[0] still has the wrong value,
		// hence, we must now swap nums[0] with nums[4-1] and get [-1, 1, 3, 4].
		while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i])
		{
			// put nums[i] at the place it belongs to (i.e. nums[nums[i]-1])
			swap(nums[i], nums[nums[i]-1]);
		}
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		// e.g. [1, -1, 3, 4], -1 is not 2, then 2 is the first missing positive
		if (nums[i] != i + 1)
		{
			return i + 1;
		}
	}

	return nums.size() + 1;
}
