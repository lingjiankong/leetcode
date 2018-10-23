// This is a boring problem. Doesn't involve in any fun algorithm.
// Just read the code and you'll understand it.
vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> res;

	if (nums.size() == 0)
	{
		return res;
	}

	// Starting index of a for the a -> b you want to fill.
	int start = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] - 1 != nums[i-1]) 
		{
			if (start == i - 1)
			{
				res.push_back(to_string(nums[i-1]));
			}
			else
			{
				res.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
			}
			start = i;
		}
	}

	if (start == nums.size() - 1) 
	{
		res.push_back(to_string(nums[start]));
	}
	else
	{
		res.push_back(to_string(nums[start]) + "->" + to_string(*nums.rbegin()));
	}

	return res;
}
