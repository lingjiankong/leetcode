vector<string> findRepeatedDnaSequences(string s)
{
	// Use an unordered_set to store repeated sequences
	// so we could eliminate the duplciates.
	unordered_set<string> repeated;

	unordered_set<string> seen;	

	for (int i = 0; i + 9 < s.size(); ++i)
	{
		string substring = s.substr(i, 10);

		if (seen.find(substring) != seen.end())
		{
			repeated.insert(substring);
				
		}
		else
		{
			seen.insert(substring);
		}
	}

	return vector<string>(repeated.begin(), repeated.end());
}
