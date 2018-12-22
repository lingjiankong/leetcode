// TODO
// Should use two std lower bound
vector<int> searchRange(vector<int>& nums, int target)
{
	int left = 0, right = nums.size();

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	if (nums[right] == target)
	{
		return {right, right + 1};
	}
	else
	{
		return {-1, -1};
	}
}
