// 1. Use unordered_map
// See also 290. Word Pattern for intuition on this one.
bool isIsomorphic(string s, string t)
{
	// Map from s to t
	unordered_map<char, char> hashS;
	
	// Map from t to s
	unordered_map<char, char> hashT;

	for (int i = 0; i < s.size(); ++i)
	{
		if (hashS.find(s[i]) != hashS.end())
		{
			if (hashS[s[i]] != t[i])
			{
				return false;
			}
		}
		else
		{
			hashS[s[i]] = t[i];
		}

		if (hashT.find(t[i]) != hashT.end())
		{
			if (hashT[t[i]] != s[i])
			{
				return false;
			}
		}
		else
		{
			hashT[t[i]] = s[i];
		}
	}

	return true;
}

// 2. Also like hash map, but you sort of implement it yourself
bool isIsomorphic(string s, string t)
{
	// 256 because there are 256 ASCII characters.
	// -1 is just arbitrary. You can initialize the numbers to -123 if you want
	// The idea is that, if letter a in mapS maps to letter b in mapT,
	// then, letter a and letter b must share the same "value" 
	// This "value" is the 'i' we assign to mapS[a] and mapT[b]
	vector<int> mapS(256, -1);
	vector<int> mapT(256, -1);

	for (int i = 0; i < s.size(); ++i)
	{
		if (mapS[s[i]] != mapT[t[i]])
		{
			return false;
		}
		// We initialized the vetor to all -1 so we can start assigning from i = 0
		// You don't have to assign i, you can assign = i + 456.
		mapS[s[i]] = mapT[t[i]] = i;
	}

	return true;
}
