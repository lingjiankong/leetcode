int removeElement(vector<int>& nums, int val)
{
	// count is the position of the first occurance of val,
	// i.e. we are sure that nums at [0, count) do not contain val.
	int count = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != val)
		{
			swap(nums[i], nums[count]);
			++count;
		}
	}

	return count;
}
