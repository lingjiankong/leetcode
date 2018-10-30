// The idea is the same as 387. First Unique Character in a String and
// 383. Ransom Note.
bool isAnagram(string s, string t)
{
	vector<int> counts(26, 0);

	for (char letter : s)
	{
		++counts[letter-'a'];
	}

	for (char letter : t)
	{
		--counter[letter-'a'];
	}

	for (int num : counts)
	{
		if (num != 0)
		{
			return false;
		}
	}

	return true;
}
