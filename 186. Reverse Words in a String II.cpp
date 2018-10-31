// We are told that:
// The input string does not contain leading or trailing spaces.
// The words are always separated by a single space.
// This makes the problem much easier compare to 151. Reverse Words in a String.
void reverseWords(vector<char>& str)
{
	// First, reverse the whole string, then reverse each word.
	reverse(str.begin(), str.end());

	// Reverse words one by one (except the last one).
	int start = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == ' ')
		{
			reverse(str.begin() + start, str.begin() + i);
			start = i + 1;
		}
	}

	// Reverse the last word.
	reverse(str.begin() + start, str.end());
}
