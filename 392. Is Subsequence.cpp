// ***
//
// Given a string s and a string t, check if s is subsequence of t.
// You may assume that there is only lower case English letters in both s and t.
// t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
// 
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
// 
// Example 1:
// s = "abc", t = "ahbgdc"
// 
// Return true.
// 
// Example 2:
// s = "axc", t = "ahbgdc"
// 
// Return false.
// 
// Follow up:
// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
//
// ***
//
// Note: this question asks about whether s is a subsequence of t,
// NOT if s is a substring of t. These two are different concepts.
//
// Iterate t, advance index of s when we found a matched char in t.
// Stop the loop whenever it reaches the end of t or we found all characters in s (reach the end of s).
// After the loop, return true if index of s is equal to its length. Otherwise, return false.
//
bool isSubsequence(string s, string t)
{
	if (s.empty())
	{
		return true;
	}

	int i = 0, j = 0;
	while (i < s.size() && j < t.size())
	{
		if (s[i] == t[j])
		{
			++i; ++j;
		}
		else
		{
			++j;
		}
	}

	return i == s.size();
}
