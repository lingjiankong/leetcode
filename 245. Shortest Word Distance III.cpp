// See also 243. Shortest Word Distance I.
int shortestWordDistance(vector<string>& words, string word1, string word2)
{
	int pos1 = -1, pos2 = -1;
	int minDis = INT_MAX;

	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i] == word1)
		{
			pos1 = i;
		}
		if (words[i] == word2)
		{
			// If word1 and word2 are the same, we assign current index to pos2, and pos1 becomes last pos2
			// (last pos2 is the last time we've seen the same word)
			// (if we don't do it, and word1 is the same as word2, then pos1 and pos2 will be the same
			// everytime that same word is encountered, which will give minDis = 0).
			// If you remove if (word1 == word2), the solution is exactly the same as 243. Shortest Word Distance I
			if (word1 == word2)
			{
				pos1 = pos2;
			}
			pos2 = i;
		}
		if (pos1 != -1 && pos2 != -1)
		{
			minDis = min(minDis, abs(pos2 - pos1));
		}
	}

	return minDis;
}
