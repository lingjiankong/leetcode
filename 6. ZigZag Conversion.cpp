// ***
//
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
// (you may want to display this pattern in a fixed font for better legibility)
// 
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// 
// Write the code that will take a string and make this conversion given a number of rows:
// 
// string convert(string s, int numRows);
// Example 1:
// 
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:
// 
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// 
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//
// ***
//
// I think this is a good intuitive question about how to use while and for loop
// to track two different indexes.
// The idea is to separate the zig zags into "L" shapes (i.e. going down then going toward upper-right),
// and put letters into vector<char> representing corresponding rows.
string convert(string s, int numRows)
{
	vector<vector<char>> stringBuilder(numRows);

	// index keeps track of letter in s.
	// i keeps track of the position in stringBuilder. 
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
