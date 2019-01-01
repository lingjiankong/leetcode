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
//
// See https://www.youtube.com/watch?v=XF0wh8M2A6E. Very good intuitive on these kinds of recursion problem.
//
//              (
//            /   \
//         ((       ()
//        /  \     /
//     (((  (()   ()(
//     ...  ...  ...
//
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
			// Return when you see some thing like "())" i.e. number of ')' is greater than number of '('.
			// Note that it is OK to have "((()" i.e. number of '(' is greater than number of ')'.
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
