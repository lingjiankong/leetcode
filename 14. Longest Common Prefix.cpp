// ***
//
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
// 
// Example 1:
// Input: ["flower","flow","flight"]
// Output: "fl"
//
// Example 2:
// Input: ["dog","racecar","car"]
// Output: ""
//
// Explanation: There is no common prefix among the input strings.
//
// Note:
// All given inputs are in lowercase letters a-z.
//
// ***
//
// Just use simple brute force solution.
string longestCommonPrefix(vector<string>& strs)
{
	if (strs.empty())
	{
		return "";
	}

	string toReturn = "";

	// Iterate letters in the first word.
	for (int j = 0; j < strs[0].size(); ++j)
	{
		char c = strs[0][j];

		// Iterate all words in strs.
		for (int i = 1; i < strs.size(); ++i)
		{
			if (j >= strs[i].size() || strs[i][j] != c)
			{
				return toReturn;
			}
		}

		toReturn += c;
	}

	return toReturn;
}
