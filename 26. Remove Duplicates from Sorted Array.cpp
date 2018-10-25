// See 27. Remove Element and 283. Move Zeros. The idea is the same.
int removeDuplicates(vector<int>& nums)
{

	if (nums.size() <= 1)
	{
		return nums.size();
	}

	// Because nums is a sorted array, nums[0] just stays at where it is,
	// therefore count starts at 1.
	//
	// count is the position of first occurance of possible duplicate elements,
	// i.e. it is possible that nums[count] = nums[count-1].
	// All elements to the left of count i.e. [0, count)
	// are guaranteed to contain no duplicate.
	int count = 1;

	for (int i = 1; i < nums.size(); ++i)
	{
		// Put all non-duplicate elements to the left of count.
		if (nums[i] != nums[count-1])
		{
			swap(nums[i], nums[count++]);
		}
	}

	return count;
}
