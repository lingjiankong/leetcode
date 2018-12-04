// ***
//
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
// Your algorithm should run in O(n) complexity.
// 
// Example:
// 
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//
// ***
int longestConsecutive(vector<int>& nums)
{
	// Use unordered_set to eliminate duplicate elements
	unordered_set<int> seen(nums.begin(), nums.end());
	int res = 0;

	for (int num : nums)
	{
		// Find those that are greater than num
		int up = num + 1;
		while (seen.find(up) != seen.end())
		{
			seen.erase(up);
			++up;
		}

		// Find those that are less than num
		int down = num - 1;
		while (seen.find(down) != seen.end())
		{
			seen.erase(down);
			--down;
		}

		res = max(res, up-down-1);
	}

	return res;
}
