// Just brute force solution
int lengthOfLastWord(string s)
{
	int length = 0;
	int lastWordEnd = 0;

	// First, find the index of first non-space character,
	// this is the end of last word.
	for (int i = s.size() - 1; i >= 0; --i)
	{
		if (s[i] != ' ')
		{
			lastWordEnd = i;
			++length;
			break;
		}
	}

	// Then, find the start of that word.
	// Before the start, there can either be a space,
	// or there could be no space in front (i.e. the word just start at index 0)
	for (int i = lastWordEnd - 1; i >= 0; --i)
	{
		if (s[i] == ' ')
		{
			break;
		}

		++length;
	}

	return length;
}
