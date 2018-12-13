// ***
//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// 
// For example, given n = 3, a solution set is:
// 
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
//
// ***
class Solution 
{

	public:
	 
		vector<string> generateParenthesis(int n) 
		{
			// Number of total '(' so far.
			int left = 0;

			// Number of total ')' so far.
			int right = 0;

			string current;
			vector<string> all;
			 
			backtrack(left, right, current, all, n);

			return all; 
		}

	private:
		
		void backtrack(int left, int right, string current, vector<string>& all, int& total)
		{
			if (left < right)
			{
				return;
			}
			 
			if (left == total && right == total)
			{
				all.push_back(current); 
			}

			if (left < total)
			{
				backtrack(left + 1, right, current + '(', all, total); 
			}

			if (right < total)
			{
				backtrack(left, right + 1, current + ')', all, total); 
			}
		}
		 
};
