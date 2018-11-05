bool isStrobogrammatic(string num)
{
	unordered_map<char, char> hash =
	{
		{'0', '0'},
		{'1', '1'},
		{'6', '9'},
		{'8', '8'},
		{'9', '6'} 
	};

	int i = 0, j = num.size() - 1;
	
	while (i <= j)
	{
		if (hash.find(num[i]) != hash.end() && num[j] == hash[num[i]])
		{
			++i, --j;
		}
		else
		{
			return false;
		}
	}
	
	return true;
}
