// Not hard to understand. Just read the code.
// The long was to prevent integer overflow. Just treat it as int.
// A similar problem is 228. Summary Ranges.
vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
{
	vector<string> res;

	long currentLow = lower;

	for (const long& num : nums)
	{
		if (num == currentLow)
		{
			++currentLow;
		}
		else if (num > currentLow)
		{
			// We are missing a number
			if (num - 1 == currentLow)
			{
				res.push_back(to_string(currentLow));
			}
			// We are missing a range
			// You can just put else here.
			else if (num - 1 > currentLow)
			{
				res.push_back(to_string(currentLow) + "->" + to_string(num-1));
			}
			currentLow = num + 1;
		}
	}

	if (currentLow == upper)
	{
		res.push_back(to_string(upper));
	}
	else if (currentLow < upper)
	{
		res.push_back(to_string(currentLow) + "->" + to_string(upper));
	}

	return res;
}
