int romanToInt(string s)
{
	if (s.empty())
	{
		return 0;
	}

	unordered_map<char, int> romanToInt =
	{
		{ 'I' , 1 },
		{ 'V' , 5 },
		{ 'X' , 10 },
		{ 'L' , 50 },
		{ 'C' , 100 },
		{ 'D' , 500 },
		{ 'M' , 1000 }
	};

	int sum = romanToInt[s.back()];

	for (int i = s.size()-2; i >= 0; --i)
	{
		if (romanToInt[s[i]] < romanToInt[s[i+1]])
		{
			sum -= romanToInt[s[i]];
		}
		else
		{
			sum += romanToInt[s[i]];
		}
	}

	return sum;
}
