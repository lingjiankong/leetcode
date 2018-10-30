// Use same idea as 387. First Unique Character in a String.
bool canConstruct(string ransomNote, string magazine)
{
	vector<int> counts(26, 0);

	for (char letter : magazine)
	{
		++counts[letter-'a'];
	}

	for (char letter : ransomNote)
	{
		--counts[letter-'a'];

		if (counts[letter-'a'] < 0)
		{
			return false;	
		}
	}

	return true;
}
