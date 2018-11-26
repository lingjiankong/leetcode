// Recursiong with memoization.
//
// For finding the solution, we check every possible prefix of that string in the dictionary of words,
// if it is found in the dictionary, then the recursive function is called for the remaining portion of that string.
// And, if in some function call it is found that the complete string is in dictionary, then it will return true.
// cache[i] stores whether the substring s[0, i) can be partitioned.
class Solution
{

	public:

		bool wordBreak(const string& s, vector<string>& wordDict)
		{
			unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
			unordered_map<int, bool> cache;
			int startIndex = 0;

			return wordBreak(startIndex, s, wordSet, cache);
		}

	private:
		
		bool wordBreak(int startIndex, const string& s, const unordered_set<string>& wordSet, unordered_map<int, bool>& cache)
		{
			// When startIndex == s.size(), there is nothing to the right of the index,
			// therefore, wordBreak returns true.
			if (startIndex == s.size())
			{
				return true;
			}

			if (cache.count(startIndex))
			{
				return cache[startIndex];
			}

			for (int endIndex = startIndex + 1; endIndex <= s.size(); ++endIndex)
			{
				if (wordSet.count(s.substr(startIndex, endIndex - startIndex)) && wordBreak(endIndex, s, wordSet, cache))
				{
					return cache[endIndex] = true;
				}
			}

			return cache[startIndex] = false;
		}

};

// Dynamic programming solution:
// We use two index pointers i and j, where i refers to the *length* of the substring (s')
// considered currently starting from the beginning of s, and j refers to the index partitioning the
// current substring s' into smaller substring s'[0, j] and s'[j+1, i].
//
// dp[i]: whether the substring s starting from 0 of length i can be partitioned.
// dp[0] = true because an empty string can always be partitioned.
bool wordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
	vector<bool> dp(s.size() + 1);
	dp[0] = true;

	for (int i = 1; i <= s.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			// The left part of the subtring can be partitioned and the right part is in dictionary.
			if (dp[j] && wordSet.count(s.substr(j, i - j)))
			{
				dp[i] = true;
				break;
			}
		}
	}

	return dp.back();
}
