// You should understand the problem just by reading the code.
//
// Example:
// s: international
// t: interxnational
// 
// Iterate all letters in the shorter string,
// When we see the difference at i = 5 (s[5] = n, t[5] = x)
// We inserting 'x' from t to s at i = 5, and then check if s and t are the same
//
// Example:
// s. redpig
// t. retpig 
//
// Now s and t has equal length, similar idea as above, replace 'd' in s with
// 't' in t, and check if s and t are the same
//
// The better solution is second one. This one just gives you intuition about the problem.
bool isOneEditDistance(string s, string t)
{
	int m = s.size();
	int n = t.size();

	// Make sure s is the shorter string.
	if (m > n)
	{
		return isOneEditDistance(t, s);
	}

	// If length of s and t differs more than one, or s and t are exactly the same, 
	// then it is not possible for s and t to have exactly one edit distance, return false.
	if (m + 1 < n || s == t)
	{
		return false;
	}

	for (int i = 0; i < m; ++i)
	{
		if (s[i] != t[i])
		{
			if (m == n)
			{
				s[i] = t[i];
			}
			else
			{
				s.insert(i, 1, t[i]);
			}

			break;
		}
	}

	// (s + t[n-1] == t) checks the edge case when the difference is at the last letter
	// For example,
	// s = "abc"
	// t = "abcd"
	return (s == t) || (s + t[n-1] == t);
}

// 2. Better solution, without modifying existing string.
bool isOneEditDistance2(const string& s, const string& t)
{	
	int m = s.size();
	int n = t.size();
	
	if (m > n)
	{	
		return isOneEditDistance(t, s);
	}

	if (m + 1 < n || s == t) 
	{
		return false;
	}
	
	// i traverse string s, j traverse string t.
	int i = 0, j = 0;
	int mismatchCount = 0;

	while (i < m && j < n)
	{
		if (s[i] != t[j])
		{
			if (++mismatchCount > 1)
			{
				return false;
			}
			if (m != n)
			{
				++j;	 
				continue;
			}
		}

		++i, ++j;
	}
	
	return true; 
}
