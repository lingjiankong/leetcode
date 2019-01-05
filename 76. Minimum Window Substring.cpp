// ***
//
// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
// 
// Example:
// 
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:
// 
// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
//
// ***
//
string minWindow(string s, string t)
{
	string toReturn = "";

	unordered_map<char, int> letterCount;

	int left = 0, count = 0, minLength = INT_MAX;

	for (char c : t)
	{
		++letterCount[c];
	}

	for (int i = 0; i < s.size(); ++i)
	{
		if (--letterCount[s[i]] >= 0)
		{
			++count;
		}

		// When count == t.size(), all letters in t appear in current sliding window.
		// Therefore you start increasing left pointer and "squeeze" the sliding window from left,
		// until right before count < t.size() (meaning a letter from t will be missing in the current sliding window),
		// that's when you start increasing the right pointer again.
		while (count == t.size())
		{
			if (i - left + 1 < minLength)
			{
				minLength = i - left + 1;
				toReturn = s.substr(left, minLength);
			}
			 
			// Even if s[left] is not in t, it doesn't matter
			// because the value will never be greater than 0.
			if (++letterCount[s[left]] > 0)
			{
				--count;
			}

			++left;
		}
	}
	
	return toReturn;
}

