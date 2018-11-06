// Note: this question asks about whether word is a *subsequence* of s,
// not if word is a *substring* of s. These two concepts are different.
// 
// Frist, traverse through s, for each letter, store the index where it has been seen.
//
// For example:
//
// "acbca"
// 'a': {0, 4}
// 'b': {1}
// 'c': {2, 3}
//
// To find if word is a subsequence of s:
// Initialize previous index to -1, then for each letter in word,
// find (binary search using std::upper_bound) the index of current letter that is greater than previous index.
// If you find such index, set it as the new previous index and continue to next letter in word;
// If you cannot find such index, it means you couldn't find the next letter after current index,
// which means word is not a subsequence of s.
class Solution
{

	public:

		int numMatchingSubseq(const string& s, vector<string>& words)
		{
			int subsequenceCount = 0;

			// For each letter, store the index where it has been seen.
			for (int i = 0; i < s.size(); ++i)
			{
				letterIndex[s[i] - 'a'].push_back(i);
			}

			for (string word : words)
			{
				if (cache.find(word) != cache.end())
				{
					subsequenceCount += cache[word];
				}
				else
				{
					subsequenceCount += isSubsequence(word);
				}

			}

			return subsequenceCount;
		}
	
	private:

		bool isSubsequence(const string& word)
		{
			int previousIndex = -1;

			for (char letter : word)
			{
				auto itr = upper_bound(letterIndex[letter - 'a'].begin(), letterIndex[letter - 'a'].end(), previousIndex);

				if (itr == letterIndex[letter - 'a'].end())
				{
					return cache[word] = false;
				}

				previousIndex = *itr;
			}

			return cache[word] = true;
		}

		// Cache if word string is a subsequence of s,
		// so we can reuse our result if we see duplicate words.
		unordered_map<string, bool> cache;

		array<vector<int>, 26> letterIndex;

};

