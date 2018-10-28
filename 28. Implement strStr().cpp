// Just brute force solution. Read the code.
int strStr(string haystack, string needle)
{
	if (needle.size() == 0)
	{
		return 0;
	}

	for (int i = 0; i < haystack.size(); ++i)
	{

		// It is not possible for the remaining haystack ot contain needle
		if (i + needle.size() > haystack.size())
		{
			break;
		}

		for (int j = 0; j < needle.size(); ++j)
		{
			if (haystack[i+j] != needle[j])
			{
				break;
			}

			if (j == needle.size()-1)
			{
				return i;
			}
		}
	}

	return -1;
}
