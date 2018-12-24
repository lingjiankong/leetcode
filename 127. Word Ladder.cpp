// ***
//
// Given two words (beginWord and endWord), and a dictionary's word list,
// find the length of shortest transformation sequence from beginWord to endWord, such that:
// - Only one letter can be changed at a time.
// - Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
// Note:
// - Return 0 if there is no such transformation sequence.
// - All words have the same length.
// - All words contain only lowercase alphabetic characters.
// - You may assume no duplicates in the word list.
// - You may assume beginWord and endWord are non-empty and are not the same.
//
// Example 1:
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// 
// Output: 5
// 
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//
// Example 2:
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// 
// Output: 0
// 
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//
// ***
//
// BFS solution.
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> dict(wordList.begin(), wordList.end());		 
	if (!dict.count(endWord))
	{
		return 0;
	}
	
	queue<string> wordQueue;
	wordQueue.push(beginWord);
	
	// BFS level, this is the number of steps between words.
	int level = 0;
	
	while (!wordQueue.empty())
	{
		// Every time we enter this loop we enter a new BFS level.
		++level;

		// For all words in current level
		int currentLevelSize = wordQueue.size();
		for (int k = 0; k < currentLevelSize; ++k)
		{				 
			string word = wordQueue.front(); wordQueue.pop();

			// Found the solution
			if (word == endWord)
			{
				return level;
			}

			// For every letter in word
			for (int i = 0; i < word.size(); i++)
			{				 
				char letter = word[i];

				// For every letter in word, traverse 'a' -> 'z'.
				for (int j = 'a'; j <= 'z'; j++)
				{
					word[i] = j;

					if (dict.count(word))
					{
						// Remember to erase the word from dict!
						dict.erase(word);
						wordQueue.push(word);					  
					}

				}

				word[i] = letter;
			}
		}
	}

	return 0;
}
