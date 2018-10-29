// Just use simple brute force solution.
// Use the strs[0] as reference, see how other words in strs
// share the same letters with strs[0]
string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0)
	{
		return "";
	}
	
	for (int i = 0; i < strs[0].size(); ++i)
	{
		char letter = strs[0][i];

		for (int j = 1; j < strs.size(); ++j)
		{
			if (i == strs[j].size() || strs[j][i] != letter)
			{
				// The second parameter is the number of characters to include in the substring
				// e.g. str.substr(10, 2) will return str at position 10, 11.
				return strs[0].substr(0, i);
			}
		}
	}

	return strs[0];
}
