// I think this is a good intuitive question about how to use while and for loop
// to track two different indexes.
// The idea is to separate the zig zags into "L" shapes (i.e. going down then going up),
// and put letters into vector<char> representing corresponding rows.
string convert(string s, int numRows)
{
	vector<vector<char>> stringBuilder(numRows);

	// index keep tracks of letter in s.
	int index = 0;
	while (index < s.size())
	{
		// Going down, i keep tracks of which row we are at.
		for (int i = 0; i < numRows && index < s.size(); ++i)
		{
			stringBuilder[i].push_back(s[index++]);
		}

		// Going up.
		// i = numRows - 2 because the last row is numRows - 1, and we want to put the letter
		// in the second last row, which is numRows - 2.
		for (int i = numRows - 2; i > 0 && index < s.size(); --i)
		{
			stringBuilder[i].push_back(s[index++]);
		}
	}

	string res = "";
	for (auto row : stringBuilder)
	{
		for (char letter : row)
		{
			res += letter;
		}
	}

	return res;
}
