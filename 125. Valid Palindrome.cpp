bool isPalindrome(string s)
{
	// Why do we have i < j instead of i <= j?
	// Because if it was the case when i == j, then there's no need to check any of the condition below,
	// because since the index is the same, s[i] must be equal to s[j], true will be returned any way.
	for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
	{
		while (!isalnum(s[i]) && i < j)
		{
			++i;
		}

		while (!isalnum(s[j]) && i < j)
		{
			--j;
		}

		if (tolower(s[i]) != tolower(s[j]))
		{
			return false;
		}
	}

	return true;
}

// Same idea.
bool isPalindrome2(string s)
{
	int i = 0, j = s.size() - 1;

	while (i < j)
	{
		if (!isalnum(s[i]))
		{
			++i;
		}
		else if (!isalnum(s[j]))
		{
			--j;
		}
		else
		{
			if (tolower(s[i++]) != tolower(s[j--])) 
			{
				return false;
			}
		}
	}

	return true;
}
