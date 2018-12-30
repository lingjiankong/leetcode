// ***
//
// Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
// 
// Example:
// 
// Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
// Output: ["2", "4->49", "51->74", "76->99"]
//
// ***
//
// Not hard to understand. Just read the code.
// The long was to prevent integer overflow. Just treat it as int.
// A similar problem is 228. Summary Ranges.
vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
{
	vector<string> toReturn;

	long currentLow = lower;

	for (long num : nums)
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
				toReturn.push_back(to_string(currentLow));
			}
			// We are missing a range
			// You can just put else here.
			else if (num - 1 > currentLow)
			{
				toReturn.push_back(to_string(currentLow) + "->" + to_string(num-1));
			}
			currentLow = num + 1;
		}
	}

	if (currentLow == upper)
	{
		toReturn.push_back(to_string(upper));
	}
	else if (currentLow < upper)
	{
		toReturn.push_back(to_string(currentLow) + "->" + to_string(upper));
	}

	return toReturn;
}
