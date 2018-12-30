// ***
//
// Given a sorted integer array without duplicates, return the summary of its ranges.
// 
// Example 1:
// 
// Input:  [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
// 
// Example 2:
// 
// Input:  [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
// Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
//
// ***
// 
// This is a boring problem. Doesn't involve in any fun algorithm.
// Just read the code and you'll understand it.
vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> toReturn;

	if (nums.size() == 0)
	{
		return toReturn;
	}

	// Starting index of a for the a -> b you want to fill.
	int start = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] - 1 != nums[i-1]) 
		{
			if (start == i - 1)
			{
				toReturn.push_back(to_string(nums[i-1]));
			}
			else
			{
				toReturn.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
			}
			start = i;
		}
	}

	if (start == nums.size() - 1) 
	{
		toReturn.push_back(to_string(nums[start]));
	}
	else
	{
		toReturn.push_back(to_string(nums[start]) + "->" + to_string(nums.back()));
	}

	return toReturn;
}
