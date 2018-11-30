// ***
//
// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
// 
// Example:
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
// 
// Input: word1 = “coding”, word2 = “practice”
// Output: 3
// Input: word1 = "makes", word2 = "coding"
// Output: 1
// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
//
// ***
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
