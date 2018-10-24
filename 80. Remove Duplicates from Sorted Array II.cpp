// This problem uses the same method as
// 26. Remove Duplicates from Sorted Array. See that problem for intuition
int removeDuplicates(vector<int>& nums)
{

	if (nums.size() <= 2)
	{
		return nums.size();
	}

    // Because nums is a sorted array, nums[0] and nums[1] just stay at where they are.
	// It is ok if they are duplicates, therefore count starts at 2.
	//
    // count is the position of first occurance of possible three duplicate elements,
    // i.e. it is possible that nums[count] = nums[count-1] = nums[count-2]. 
    // All elements in [0, count) are guaranteed to contain at most two duplicates.
    int count = 2; 
     
	for (int i = 2; i < nums.size(); ++i)
	{
		if (nums[i] != nums[count-2])
		{
			swap(nums[count], nums[i]);
			++count;
		}
	}

	return count;
}
