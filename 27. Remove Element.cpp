// The thinking process if same as 283. Move Zeros.
//
// Everything to the left of count does not contain val.
// i.e. we are sure that nums at [0, count) do not contain val.
//
// You may also call count something like "valStart".
// since verything to the left of valStart does not contain val.
int removeElement(vector<int>& nums, int val)
{
	int count = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		// Put all non-val elements to the left of count.
		if (nums[i] != val)
		{
			swap(nums[i], nums[count++]);
		}
	}

	return count;
}
