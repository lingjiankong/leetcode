// ***
//
// Given a string containing digits from 2-9 inclusive (telephone numbers),
// return all possible letter combinations that the number could represent.
// 
// ***
class Solution
{

	public:

		vector<string> letterCombinations(string digits)
		{
			mDict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

			string current;
			vector<string> all;
			int startIndex = 0;

			backtrack(digits, startIndex, current, all);

			return all;
		}

	private:

		void backtrack(string& digits, int startIndex, string& current, vector<string>& all)
		{
			// We check if !current.empty() simply to deal with the case when digits = "",
			// we do not want to return {""}. You can move it to letterCombinations if you wish.
			if (startIndex == digits.size() && !current.empty())
			{
				all.push_back(current);
				return;
			}

			string letters = mDict[digits[startIndex] - '0'];

			for (int i = 0; i < letters.size(); ++i)
			{
				current.push_back(letters[i]);
				backtrack(digits, startIndex + 1, current, all)
				current.pop_back();
			}
		}

		vector<string> mDict;

};
