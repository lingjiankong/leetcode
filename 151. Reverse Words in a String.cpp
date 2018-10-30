// This question is somewhat stupid. Doesn't involve too many algorithms.
// Don't worry too much if you don't get it.
// See https://leetcode.com/problems/reverse-words-in-a-string/discuss/47740/In-place-simple-solution
void reverseWords(string &s)
{
	// First, reverse the whole string, then reverse each word.
	reverse(s.begin(), s.end());

	// Current position available for insertion
	// We do this so we don't need to deal with multiple white spaces in between words.
	// We place reversed words at position denoted by storeIndex, separate each one by only one space
	int storeIndex = 0;

	// i: the beginning of one word
	for (int i = 0; i < s.size(); i++)
	{
		// Now we've seen the beginning index of a new word, which is i
		if (s[i] != ' ')
		{
			// Put blank space after storeIndex if word is not the first one.
			// This is important because we can separate each word with only one space.
			// Example:
			// world_myxxxxxxxxxxolleh
			//         ^         ^
			//     storeIndex    i
			// 
			// world_my_xxxxxxxxxolleh
			//          ^ 
			//      storeIndex
			//
			// world_my_ollehxxxxolleh
			//
			// world_my_helloxxxxolleh
			//
			if (storeIndex != 0)
			{
				s[storeIndex++] = ' ';
			}

			// j is one past the end of one word
			// i.e. j points to the trailing space of that word
			// (assume word is not the last one with no trailing space)
			int j = i;

			// Copy the the entire word (including the trailing space)
			// one by one to start at storeIndex.
			while (j < s.size() && s[j] != ' ')
			{
				s[storeIndex++] = s[j++];
			}

			// Copy is finished, now
			// storeIndex and j are now both pointing to a space
			// (if word is not the last one with no trailing space)
			// We do not care about this space when reverse
			// s.begin() + storeIndex is this space. It is not among what we reverse.
			reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);

			// Current begin becomes one past end of last word (i.e. the trailing space).
			i = j;
		}
	}

	s.erase(s.begin() + storeIndex, s.end());
}
