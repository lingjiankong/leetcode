// ***
//
// Given an unsorted array of integers, find the length of longest increasing subsequence.
// 
// Example:
// 
// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
//
// ***
//
// See also 128. Longest Consecutive Sequence. In that question, order of element does not matter.
//
// DP solution.
int lengthOfLIS(vector<int>& nums)
{
	// dp[i] stores the length of longest subsequence that ends at position i.
	// Remember to initialize all elements in dp to 1 because a single number itself is a subsequence of length 1.
	vector<int> dp(nums.size(), 1);

	int longestLength = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[j] < nums[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		longestLength = max(longestLength, dp[i]);
	}

	return longestLength;
}

// Binary search. Took me a while to understand it. Just memorize it.
// tails is an array storing the smallest tail (i.e. the last elemet) of all increasing subsequences with length i + 1 in tails[i].
// For example, say we have nums = [4, 5, 6, 3], then all the available increasing subsequences are:
// 
// length = 1   :      [4], [5], [6], [3]   => tails[0] = 3
// length = 2   :      [4, 5], [5, 6]       => tails[1] = 5
// length = 3   :      [4, 5, 6]            => tails[2] = 6
//
// tails is an increasing array, so we can do binary search on it.
//
// Traverse through nums:
// 1. If nums[i] > the right most element in tails, then add nums[i] to the end of tails (now tails.size() has increased by 1).
// 2. If nums[i] < the left most element in tails, replace the leftmost element to nums[i] (note tails.size() does not change in this case).
// 3. Otherwise, find lower_bound(nums[i]) in tails, and replace that element with nums[i] (note tails.size() does not change in this case).
//
// Finally, tails.size() is the length of longest increasing subsequence.
//
// For example, in the above example, if our incoming nums[i] = 4, then lower_bound(tails.begin(), tails.end(), nums[i]) is tails[1] = 5,
// so we can update tails[1] = 5  to tails[1] = 4. i.e. A subsequence of length 2: [3, 4] can be formed.
int lengthOfLIS(vector<int>& nums)
{
    vector<int> tails;

    for(int i = 0; i < nums.size(); ++i)
	{
        auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
        if (it == tails.end())
		{
			tails.push_back(nums[i]);
		}
        else
		{
			*it = nums[i];
		}
    }

    return tails.size();
}
