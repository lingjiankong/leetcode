// ***
//
// Given a column title as appear in an Excel sheet, return its corresponding column number.
// 
// For example:
// 
//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28 
//     ...
//
// ***
//
// This question is the same as saying converting base 26 numbers to base 10 numbers.
//
// See also 168. Excel Sheet Column Title
int titleToNumber(string s)
{
	int columnNumber = 0;

	int multiplier = 1;
	for (int i = s.size() - 1; i >= 0; --i)	
	{
		// s[i] - 'A' + 1:
		// "+ 1" here so that `A` is mapped to 1, 'B' is mapped to 2...
		columnNumber +=	multiplier * (s[i] + 1 - 'A');
		multiplier *= 26;
	}

	return columnNumber;
}
