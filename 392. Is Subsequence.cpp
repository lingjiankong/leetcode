// Note: this question asks about whether s is a subsequence of t,
// not if s is a substring of t. These two are different concepts.
// The followup of this question is 792. Number of Matching Subsequences.
//
// Iterate t, advance index of s when we found a matched char in t.
// Stop the loop whenever it reaches the end of t or we found all characters in s (reach the end of s).
// After the loop, return true if index of s is equal to its length. Otherwise, return false.
//
bool isSubsequence(const string& s, const string& t)
{
	int sIndex = 0;
	int tIndex = 0;
	int count = 0;

	while (sIndex < s.size() && tIndex < t.size()) 
	{
		if (t[tIndex] == s[sIndex])
		{
			++count;
			++tIndex;
		}

		++sIndex;
	}

	return count == s.size();
}
