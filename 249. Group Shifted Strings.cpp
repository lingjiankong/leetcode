// The idea is very simple, for words which share the same "shifting sequence",
// for example "cde", "efg", "yza", we find their sharing offsetted string: abc,
// for example, "cde" offset 2 to get "abc", "efg" offset 4 to get "abc", "yza" offset 24 to get "abc",
// "abc" is the their sharing "shifting sequence", which is the key in the hash map.
class Solution
{

	public:

		vector<vector<string>> groupStrings(vector<string>& strings)
		{
			for (auto word : strings)
			{
				string shiftedWord = shift(word);
				hash[shiftedWord].push_back(word);
			}

			vector<vector<string>> res;

			for (auto element : hash)
			{
				res.push_back(element.second);
			}

			return res;
		}

	private:

		string shift(const string& word)
		{
			int offset = word[0] - 'a';

			string shiftedWord;

			for (char letter : word)
			{
				int diff = (letter - 'a') - offset; 
				if (diff < 0)
				{
					diff += 26; 
				}
				shiftedWord += '#' + to_string(diff);
			}

			return shiftedWord;
		}

		unordered_map<string, vector<string>> hash;

};
