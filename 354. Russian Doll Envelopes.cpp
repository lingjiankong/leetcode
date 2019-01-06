// ***
//
// You have a number of envelopes with widths and heights given as a pair of integers (w, h).
// One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
// 
// What is the maximum number of envelopes can you Russian doll? (put one inside other)
// 
// Note:
// Rotation is not allowed.
// 
// Example:
// 
// Input: [[5,4],[6,4],[6,7],[2,3]]
// Output: 3 
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
//
// ***
//
// This is the 2D version of 300. Longest Increasing Subsequence.
//
// DP solution O(n^2):
int maxEnvelopes(vector<pair<int, int>>& envelopes)
{
	// dp[i] stores the length of longest subsequence that ends at position i (i.e. number of envelopes).
	vector<int> dp(envelopes.size(), 1);
	int maxEnvelopes = 0;

	sort(envelopes.begin(), envelopes.end());

	for (int i = 0; i < envelopes.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		maxEnvelopes = max(maxEnvelopes, dp[i]);
	}

	return maxEnvelopes;
}

// Binary search solution O(nlogn). This is almost the same as 300. Longest Increasing Subsequence.
// You would need to memorize it.
int maxEnvelopes(vector<pair<int, int>>& envelopes)
{
	vector<int> heightTails;

	// Sort the width in ascending order. If witdh is the same, then sort height in DESCENDING order.
	// Why sort width in ascending order but height in descending order? Because envelopes with the same width can't fit into each other,
	// so if you sort height in descending order when width is the same, then when you find longest increasing subsequence (longest increasing height),
	// you don't need to take care about the case when width is the same.
	sort(envelopes.begin(), envelopes.end(), [] (const pair<int, int>& a, const pair<int, int>& b)
		{
			return a.first < b.first ||
			a.first == b.first && a.second > b.second;
		});

	for(int i = 0; i < envelopes.size(); ++i)
	{
		int height = envelopes[i].second;

		auto it = lower_bound(heightTails.begin(), heightTails.end(), height);
		if (it == heightTails.end())
		{
			heightTails.push_back(height);
		}
		else
		{
			*it = height;
		}
	}

	return heightTails.size();
}
