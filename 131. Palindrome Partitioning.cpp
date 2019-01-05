// ***
//
// Given a string s, partition s such that every substring of the partition is a palindrome.
// 
// Return all possible palindrome partitioning of s.
// 
// Example:
// 
// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
//
// ***

class Solution
{

	public:

		vector<vector<string>> partition(string s)
		{
			vector<string> current;
			vector<vector<string>> all;

			int startIndex = 0;

			backtrack(s, startIndex, current, all);

			return all;
		}

	private:

		void backtrack(string s, int startIndex, vector<string>& current, vector<vector<string>>& all)
		{
			if (startIndex == s.size())
			{
				all.push_back(current);
				return;
			}

			for (int i = startIndex; i < s.size(); ++i)
			{
				if (isPalindrome(s, startIndex, i))
				{
					// Why i - startIndex + 1?  At first when i = startIndex you are testing if a single letter is palindrome.
					// A single letter must be palindrome, so you add that single letter to current and iteratively check the rest.
					current.push_back(s.substr(startIndex, i - startIndex + 1));
					backtrack(s, i + 1, current, all);
					current.pop_back();
				}
			}
		}

		bool isPalindrome(string s, int left, int right)
		{
			while (left < right)
			{
				if (s[left++] != s[right--])
				{
					return false;
				}
			}

			return true;
		}

};
