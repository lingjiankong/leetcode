// This one uses the same idea as 205. Isomorphic Strings.
// See that question for intuition on this one.
// Especially the comments in the second implementation.
bool wordPattern(string pattern, string str)
{
	unordered_map<char, int> charToInt;
	unordered_map<string, int> stringToInt;

	istringstream stream(str);

	int i = 0;
	for (string word; stream >> word; ++i)
	{
		if (charToInt.find(pattern[i]) != charToInt.end() && stringToInt.find(word) != stringToInt.end())
		{
			if (charToInt[pattern[i]] != stringToInt[word])
			{
				return false;
			}
		}
		else if (charToInt.find(pattern[i]) != charToInt.end() || stringToInt.find(word) != stringToInt.end())
		{
			return false;
		}
		else
		{
			charToInt[pattern[i]] = stringToInt[word] = i;
		}
	}

	// In this case, we've finished all words in str but still have char in pattern left.
	// This is the case where lengthOf(pattern) != numberOfWords(str), must return false.
	if (i != pattern.size())
	{
		return false;
	}

	return true;
}
