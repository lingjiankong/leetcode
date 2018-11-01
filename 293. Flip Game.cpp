// Simple traverse the tring, if you see two consecutive ++,
// Turn them into -- and push back the resulting string,
// then you revert those -- to the original ++ and continue the iteration.
//
// In these kind of question, I prefer for (int i = 1; i < s.size(); ++i)
// rather than for (int i = 0; i < s.size()-1; ++i),
// because container.size() is always an unsigned int,
// if the container size is 0, then 0-1 overflows.
vector<string> generatePossibleNextMoves(string s)
{
	vector<string> res;

	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i-1] == '+' && s[i] == '+')
		{
			s[i-1] = s[i] = '-';
			res.push_back(s);
			s[i-1] = s[i] = '+';
		}
	}

	return res;
}
