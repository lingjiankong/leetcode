int shortestDistance(vector<string>& words, string word1, string word2)
{
	int pos1 = -1, pos2 = -1;
	int minDis = INT_MAX;

	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i] == word1)
		{
			pos1 = i;
			if (pos2 != -1)
			{
				minDis = min(minDis, pos1 - pos2);
			}
		}
		else if (words[i] == word2)
		{
			pos2 = i;
			if (pos1 != -1)
			{
				minDis = min(minDis, pos2 - pos1);
			}
		}
	}

	return minDis;
}
