// ***
//
// Find all possible combinations of k numbers that add up to a number n,
// given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
// The solution set must not contain duplicate combinations.
//
// Example 1:
// Input: k = 3, n = 7
// Output: [[1,2,4]]
//
// Example 2:
// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]
//
// ***
//
// This question looks more like 77. Combinations. Look at the code and see their difference.
class Solution
{

	public:

		vector<vector<int>> combinationSum3(int k, int n)
		{
			vector<int> current;
			vector<vector<int>> all;

			int startNum = 1;

			backtrack(k, n, startNum, current, all);

			return all;
		}
	
	private:

		void backtrack(int k, int n, int startNum, vector<int>& current, vector<vector<int>>& all)
		{
			if (k == 0 && n == 0)
			{
				all.push_back(current);
				return;
			}

			for (int num = startNum; num <= 9; ++num)
			{
				if (num > n)
				{
					break;
				}

				current.push_back(num);
				backtrack(k - 1, n - num, num + 1, current, all);
				current.pop_back();
			}
		}

};
