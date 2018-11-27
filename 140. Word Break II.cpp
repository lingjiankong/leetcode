// Recursive solution. This question is hard to understand.
class Solution
{

	public:

		vector<string> wordBreak(string s, vector<string>& wordDict)
		{
			unordered_map<string, vector<string>> cache;
			return wordBreak(s, wordDict, cache);
		}

	private:

		// Returns all sentences (in terms of vector<string>) that can be formed be string s.
		vector<string> wordBreak(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& cache) {

			if (cache.count(s))
			{
				return cache[s];
			}

			// If s.empty() it indicates we are at the last word, no space is needed.
			if (s.empty())
			{
				return {""};
			}

			vector<string> sentences;

			for (string word : wordDict)
			{
				if (s.substr(0, word.size()) == word)
				{
					vector<string> rem = wordBreak(s.substr(word.size()), wordDict, cache);

					for (string sentence : rem)
					{
						sentences.push_back(word + (sentence.empty() ? "" : " ") + sentence);
					}
				}
			}

			return cache[s] = sentences;
		}

};
