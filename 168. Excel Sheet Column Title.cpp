// ***
//
// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
// 
// For example:
// 
//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB
//     ...
//
// ***
//
// This question is the same as saying converting base 10 numbers to base 26 numbers.
//
// Use recursion:
string convertToTitle(int n)
{
	if (n == 0)
	{
		return "";
	}

	return covertToTitle((n-1) / 26) + (char)('A' + (n-1) % 26);
}

// Another way, similar as above.
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
