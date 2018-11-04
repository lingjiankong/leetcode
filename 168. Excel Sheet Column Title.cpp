// Use recursion:
string convertToTitle(int n)
{
	if (n == 0)
	{
		return "";
	}

	// Why n-1? Think about what happens when n = 26, you want to map it to Z.
	// If you have n/26 rather than (n-1)/26, 26 will be mapped to AA instead of Z.
	return covertToTitle((n-1) / 26) + (char)('A' + (n-1) % 26);
}

// Another way, similar to above.
string convertToTitle(int n)
{
	string title;

	while (n)
	{
		title = (char)('A' + (n-1) % 26) + title;
		n = (n-1) / 26;
	}

	return title;
}

// When I was doing this question I was thinking about, what if instead of
// map 1 -> A, 2 -> B, ..., we were asked to map 0 -> A, 1 -> B ... ?
// I think in that case you should just covert 0 based to 1 based index,
// if you are dealing with 0 based index here it will be too complex and messy...
