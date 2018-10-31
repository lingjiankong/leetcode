string reverseVowels(string s)
{
	unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

	int i = 0;
	int j = s.size() - 1;

	while (i < j)
	{
		if (vowels.find(s[i]) == vowels.end())
		{
			++i;
		}

		if (vowels.find(s[j]) == vowels.end())
		{
			--j;
		}

		if (vowels.find(s[i]) != vowels.end() && vowels.find(s[j]) != vowels.end())	
		{
				swap(s[i++], s[j--]);
		}
	}

	return s;
}
